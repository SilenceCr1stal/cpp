#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
    int *age = new int;
    *age = 17;
    cout << *age << endl;
    delete age;
    age = new int;
    *age = 18;
    cout << *age << endl;
    delete age;
    return 0;
}
