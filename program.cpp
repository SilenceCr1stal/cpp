#include <iostream>
#include <string>


int main(int argc, char** argv) {
    
    int* age = new int;

    *age = 17;

    int* age2 = new int;

    *age2 = 28;

    std::cout << *age << " " << age << std::endl;

    age = nullptr;

    age = age2;

    std::cout << *age << " " << age << " " << *age2 << " " << age2 << std::endl;

    return 0;
}
/*
    17 0x55579e72ceb0
    28 0x55579e72ced0 28 0x55579e72ced0
*/