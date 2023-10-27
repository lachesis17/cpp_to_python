#include <iostream>
using namespace std;

// the shared object *.so file doesn't need main() with extern "C" {}
// compile this into a shared object library to use with ctypes import to python with:
// g++ -fPIC -shared -o func_test.so fizz_func.cpp
// https://stackoverflow.com/a/64084123/15222030
 
int fizz(int i) {
    for (int x = 1; x <= i; x++) {
        if (x % 5 == 0 && x % 3 == 0) {
            cout << x << " FizzBuzz!\n";
        }
        else if (x % 3 == 0) {
            cout << x << " Fizz\n";
        }
        else if (x % 5 == 0) {
            cout << x << " Buzz\n";
        }
        else {
            cout << x << "\n";
        }
    }
    return 0;
}

extern "C" {
    int fizzbuzz_function(int a)
    {
        return fizz(a);
    }
}