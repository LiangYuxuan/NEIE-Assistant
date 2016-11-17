from ctypes import *
import os

def encode(string):
    lib = cdll.LoadLibrary(os.getcwd() + '/C++/encode.so')
    lib.python.restype = c_char_p
    lib.python.argtypes = [c_char_p]
    string = create_string_buffer(string)
    return lib.python(string)

def decode(string):
    lib = cdll.LoadLibrary(os.getcwd() + '/C++/decode.so')
    lib.python.restype = c_char_p
    lib.python.argtypes = [c_char_p]
    string = create_string_buffer(string)
    return lib.python(string)

os.system('make -C C++ > /dev/null');
string = raw_input('input string: ')
result = encode(string)
print "encode: " + result
print "decode: " + decode(result)
