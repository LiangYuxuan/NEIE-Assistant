#!/usr/bin/python
# coding=utf-8
import argparse
import json
import os
import random

from library import library

var = {}

# use argparse to read command line
parser = argparse.ArgumentParser(description='A small, cross-platform program for NEIE.')
parser.add_argument('-s', '--path', type=str, help='path to server, may contain ip and port')
parser.add_argument('-u', '--username', type=str, help='username to login')
parser.add_argument('-p', '--password', type=str, help='password to login')
parser.add_argument('-t', '--type', type=str, help='rwt or vls')
parser.add_argument('-l', '--level', type=str, help='current level')

parser.add_argument('-ac', '--activation', help='try to activate user first', action='store_true')

parser.add_argument('-nf', '--no-file', help='stop read and write information to config.json', action='store_true')

parser.add_argument('--end-unit', help='stop at a unit before all unit learned')

parser.add_argument('--min-time', type=int, default=60, help='min time to learn a unit, default 60')
parser.add_argument('--max-time', type=int, default=120, help='max time to learn a unit, default 120')
parser.add_argument('--min-mark', type=int, default=80, help='min mark to learn a unit, default 80')
parser.add_argument('--max-mark', type=int, default=100, help='max mark to learn a unit, default 100')
args = parser.parse_args()

var['path'] = args.path
var['username'] = args.username
var['password'] = args.password
var['type'] = args.type
var['level'] = args.level

var['end-unit'] = args.end_unit

var['min-time'] = args.min_time
var['max-time'] = args.max_time
var['min-mark'] = args.min_mark
var['max-mark'] = args.max_mark

# sync information with config.json
if args.no_file == False:
    config_file = os.getcwd() + '/config.json'
    if os.path.isfile(config_file) == False:
        with open(config_file, 'w+') as f:
            pass
    with open(config_file, 'r+') as f:
        try:
            obj = json.load(f)
        except:
            obj = {}


        def sync(var, obj, names):
            for name in names:
                try:
                    obj[name]
                except:
                    obj[name] = None
                if var[name] is None:
                    var[name] = obj[name]
                elif var[name] != obj[name]:
                    obj[name] = var[name]


        sync(var, obj, [name for name in var])
        f.seek(0)
        json.dump(obj, f)

# check necessary arguments
if var['path'] is None or var['username'] is None or var['password'] is None \
        or var['type'] is None or var['level'] is None:
    library.fail('missing required var')
    exit()

# Var init
if var['type'] == 'rwt':
    from rwt import *

    learn = learn_rwt(var['path'], var['username'], var['password'], var['level'])
else:
    from vls import *

    learn = learn_vls(var['path'], var['username'], var['password'], var['level'])
# Activation
if args.activation == True:
    print('Get Activation Code at http://www.neie.edu.cn/License/LicenseActivation.aspx')
    SerialNumber = input('Serial Number: ')
    LicenseNumber = input('License Number: ')
    ActivationCode = input('Activation Code: ')

    print('Confirm your information')
    print('Path: ' + var['path'])
    print('Username: ' + var['username'])
    print('Level: ' + var['level'])
    print('Serial Number: ' + SerialNumber)
    print('License Number: ' + LicenseNumber)
    print('Activation Code: ' + ActivationCode)

    answer = input('Is above information all right? (y/n)')
    if answer == 'Y' or answer == 'y':
        SerialNumber = SerialNumber.replace(' ', '').replace('-', '')
        LicenseNumber = LicenseNumber.replace(' ', '').replace('-', '')
        ActivationCode = ActivationCode.replace(' ', '').replace('-', '')
        active(learn, SerialNumber, LicenseNumber, ActivationCode)
    else:
        exit()

# Login
if args.activation == False:
    status = login(learn)

# Get Progress
status = get_progress(learn)
if status == '1':
    fetch = library.fetch(var['type'], learn.level, learn.SectionID)
    if fetch['next']['unit'] != learn.UnitID:
        update_unit(learn)
        learn.UnitID = fetch['next']['unit']
        learn.SectionID = fetch['next']['section']

# Learn English
while True:
    learn.GetServerTime()
    library.success('learning ' + var['type'] + ': unit ' + learn.UnitID + ', section ' + learn.SectionID)
    library.timer(random.randint(var['min-time'], var['max-time']))
    library.success('finished ' + var['type'] + ': unit ' + learn.UnitID + ', section ' + learn.SectionID)

    fetch = library.fetch(var['type'], learn.level, learn.SectionID)
    if fetch['problem'] == 0:
        score = 0
    else:
        # Get int in next two var
        min_problem = int(var['min-mark'] * fetch['problem'] / 100) + 1
        max_problem = int(var['max-mark'] * fetch['problem'] / 100)
        if min_problem > max_problem:
            min_problem = max_problem
        score = random.randint(min_problem, max_problem) * 100.0 / fetch['problem']
    status = end_section(learn, score)

    try:
        fetch['next']
    except:
        # end of all section
        status = update_unit(learn)
        break

    if fetch['next']['unit'] != learn.UnitID:
        status = update_unit(learn)
        if learn.UnitID == var['end-unit']:
            break
        learn.UnitID = fetch['next']['unit']
    learn.SectionID = fetch['next']['section']

    status = start_section(learn)
