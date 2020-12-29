#include <iostream>
#include <string.h>
#include <ctime>

int v[10] = {42};
int& g(int i) {
    return v[i];
}

int main(int argc, char **argv) {
    
    g(3) = 7;

    std::cout << v[1] << v[2] << v[3] << std::endl;

    return 0;
}
