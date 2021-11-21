#!/user/bin/python

from ctypes import *

def main():
    lib = cdll.LoadLibrary('/home/user/Desktop/cpp_python_shared_library/exe.so')

    func          = lib.count_PU_DO_Locations
    func.argtypes = [c_char_p, POINTER(c_int), POINTER(c_int)]

    pu_count, do_count = c_int(), c_int()

    func(b'/home/user/Desktop/cpp_python_shared_library/out.bin', pu_count, do_count)
    print(pu_count.value)
    print(do_count.value)

if __name__ == '__main__':
    main()
