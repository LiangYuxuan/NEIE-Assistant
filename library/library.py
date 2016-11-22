from ctypes import *
import os

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
