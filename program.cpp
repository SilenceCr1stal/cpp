#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    unsigned short int age = 17;
    int num = age << 2; // 68
    cout << num << endl;
    int num2 = age >> 3; // 2
    cout << num2 << endl;
    age |= num; // 85
    cout << age << endl;
    age ^= num2; // 87
    cout << age << endl;
    num &= num2; // 0
    cout << num << endl;
    return 0;
}
