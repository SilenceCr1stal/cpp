#include <iostream>
#include <ctime>

using namespace std;

unsigned long int Factorial(unsigned long int num);

int main(int argc, char **argv) {

    cout << Factorial(5) << endl;
    return 0;
}

unsigned long int Factorial(unsigned long int num) {
    if (num == 1) 
        return 1;
    
    return num * Factorial(num - 1);
}