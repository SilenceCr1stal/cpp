#include <iostream>
#include <string>
#include "age.h"
using namespace std;

int main(int argc, char **argv) {
    int *p = new int;
    *p = 17;
    cout << *p << endl;
    delete p;
    p = new int;
    *p = 18;
    cout << *p << endl << endl;
    delete p;
    int a = age(21);
    cout << a;
    return 0;
}