#include <iostream>
#include <ctime>

using namespace std;

template <class A, class B>
B getSomething(A a, B b);

int main(int argc, char **argv) {
    cout << getSomething(17, 8.6) << endl;
    return 0;
}

template <class A, class B>
B getSomething(A a, B b) {
    return a + b;
}
