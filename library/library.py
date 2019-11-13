import json
import os
import time
from ctypes import *
from sys import stdout

from . import termcolor

# Model Encode and Decode
os.system('make -C library/C++/ > /dev/null')


def encode(string):
    lib = cdll.LoadLibrary(os.getcwd() + '/library/C++/encode.so')
    lib.python.restype = c_char_p
    lib.python.argtypes = [c_char_p]
    string = create_string_buffer(string.encode(encoding="GBK"))
    return lib.python(string).decode(encoding="GBK")


def decode(string):
    lib = cdll.LoadLibrary(os.getcwd() + '/library/C++/decode.so')
    lib.python.restype = c_char_p
    lib.python.argtypes = [c_char_p]
    string = create_string_buffer(string.encode(encoding="GBK"))
    return lib.python(string).decode(encoding="GBK")


# Model Color Print
def success(string):
    termcolor.cprint(string, 'green')


def fail(string):
    termcolor.cprint(string, 'red')


def warning(string):
    termcolor.cprint(string, 'yellow')


# Model Timer
def timer(left):
    left = int(left)
    while left > 0:
        stdout.write("time left: " + "%i " % left, )
        stdout.flush()
        time.sleep(1)
        stdout.write("\r\r", )
        left -= 1


# Model Database
def fetch(type, level, sectionID):
    with open(os.getcwd() + '/database/' + type + '/lv' + level + '.json', 'r') as f:
        arr = json.load(f)
    flag = False
    result = {}
    for section in arr:
        if flag == True:
            result['next'] = {'section': section['section'], 'unit': section['unit']}
            break
        if section['section'] == sectionID:
            flag = True
            result['problem'] = section['problem']
    return result
