#include <iostream>
#include <ctime>

using namespace std;

unsigned long int Factorial(unsigned long int num);

int main(int argc, char **argv) {

<<<<<<< HEAD
    city *town = new city(3800000, "USA", build1);

    town->printInfo();
    delete town;
    delete build1;
    delete human1;
    delete date;

=======
    cout << Factorial(5) << endl;
>>>>>>> edae2ff31295e7674aead6752619370dc778c3e2
    return 0;
}

unsigned long int Factorial(unsigned long int num) {
    if (num == 1) 
        return 1;
    
    return num * Factorial(num - 1);
}
