#include <iostream>
#include <cmath>
#include <string>
#include <string.h>

template<typename Type>
Type getSum(Type a, Type b) {
    return a + b;
}
template<typename Type>
Type getComp(Type a, Type b) {
    return a * b;
}
template<typename Type>
Type getDiv(Type a, Type b) {
    return a / b;
}

template<typename Type>
void ShowInfo(Type(*func)(Type a, Type b), Type a, Type b) {
    std::cout << func(a, b) << std::endl;
}

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");

    char* name;

    double num1 = 7.5, num2 = 1.5;

    goto sum;

    std::cin >> name;

    sum:

    ShowInfo(getSum, num1, num2);

    return 0;
}
