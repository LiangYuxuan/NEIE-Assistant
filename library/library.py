from ctypes import *
import os, sys, time, json

sys.path.append(os.getcwd() + '/library')
import termcolor


# Model Encode and Decode
os.system('make -C library/C++/ > /dev/null')

def encode(string):
    lib = cdll.LoadLibrary(os.getcwd() + '/library/C++/encode.so')
    lib.python.restype = c_char_p
    lib.python.argtypes = [c_char_p]
    string = create_string_buffer(string)
    return lib.python(string)

def decode(string):
    lib = cdll.LoadLibrary(os.getcwd() + '/library/C++/decode.so')
    lib.python.restype = c_char_p
    lib.python.argtypes = [c_char_p]
    string = create_string_buffer(string)
    return lib.python(string)


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
        print "time left: " + "%i " % left,
        sys.stdout.flush()
        time.sleep(1)
        print "\r\r",
        left -= 1


# Model Database
def fetch(level, sectionID):
    with open(os.getcwd() + '/database/lv' + level + '.json', 'r') as f:
        obj = json.load(f)
    arr = obj['level' + level]
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
