#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
    int age;
    cout << "How old are you? - ";
    cin >> age;
    cout << "i'm " << age << "." << endl;
    int *pointer;
    pointer = &age;
    cout << pointer << endl;
    sprintf(age);
    return 0;
}