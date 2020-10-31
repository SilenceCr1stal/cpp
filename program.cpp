#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    cout << age(21) << endl;
    int *p = NULL;
    p = new int[5];
    p[0] = 17;
    cout << p << endl << p[0] << endl;
    delete [] p;
    cout << p << endl << p[0] << endl;
    return 0;
}
