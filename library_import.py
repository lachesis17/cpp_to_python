import ctypes
import os 

dir_path = os.path.dirname(os.path.realpath(__file__))
handle = ctypes.CDLL(dir_path + "/func_test.so", winmode=0)   

handle.fizzbuzz_function.argtypes = [ctypes.c_int] 
  
def FizzBuzz(num):
    return handle.fizzbuzz_function(num)

dir_path = os.path.dirname(os.path.realpath(__file__))
handle_p = ctypes.CDLL(dir_path + "/planet_lib.so", winmode=0)   

handle_p.planet_convert.argtypes = [] 
  
def Planets():
    return handle_p.planet_convert()