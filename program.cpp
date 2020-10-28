#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
    int age = 17;
    int *pointer = &age;
    cout << pointer << endl;
    int someNum = 34;
    *pointer = someNum + *pointer;
    cout << *pointer << endl;
    return 0;
}