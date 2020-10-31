#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    cout << sizeof(int) << endl;
    int *p = NULL;
    cout << sizeof(*p) << " " << sizeof(p) << " " << p << endl;
    int age = 17;
    cout << "sizeof \'age\' = " << sizeof(age) << endl;
    string name = "sizeof empty strsizeof empty strsizeof empty strsizeof empty strsizeof empty strsizeof empty strsizeof empty strsizeof empty strsizeof empty str";
    cout << "sizeof empty str = " << sizeof(string) << " and name = " << sizeof(name) << endl;

    int arr[33];
    cout << "Quantity of elements in a array: " << sizeof(arr) / sizeof(arr[0]) << endl;
    return 0;
}

/*
4
4 8 0
sizeof 'age' = 4
sizeof empty str = 32 and name = 32
Quantity of elements in a array: 33
*/