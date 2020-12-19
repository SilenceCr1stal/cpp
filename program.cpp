#include <iostream>
#include <string>
#include <time.h>
#define SIZE 5
#define SIZE_LOW 4
#define SIZE_LOW_LOW 3

int main(int argc, char** argv) {
    srand(time(NULL));
    
    int ***nums = new int** [SIZE];

    for (int i = 0; i < SIZE; i++) {
        nums[i] = new int* [SIZE_LOW];
        for (int j = 0; j < SIZE_LOW; j++) {
            *(*(nums + i) + j) = new int [SIZE_LOW_LOW];
            for (int k = 0; k < SIZE_LOW_LOW; k++) {
                *(*(*(nums + i) + j) + k) = rand() % 100;
                std::cout << *(*(*(nums + i) + j) + k) << "\t";
            }
            std::cout << "===================\t";
            delete [] *(*(nums + i) + j);
        }
        std::cout << std::endl;
        delete [] *(nums + i);
    }

    delete [] nums;

    return 0;
}
