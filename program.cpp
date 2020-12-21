#include <iostream>
#include <string>
#include <time.h>
#define SIZE 5
#define SIZE_LOW 4
#define SIZE_LOW_LOW 3

void FillArray(int** nums, const int size) {
    for (int i = 0; i < size; i++) {
        *(nums + i) = new int [size];
        for (int j = 0; j < size; j++) {
            *(*(nums + i) + j) = rand() % 100;
        }
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    
    int** nums = new int* [SIZE];

    FillArray(nums, SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << *(*(nums + i) + j) << std::endl;
        }
        if (i == SIZE - 1) {
            std::cout << "======================" << std::endl;
            }
    }

    int** nums2 = new int* [SIZE_LOW_LOW];

    FillArray(nums2, SIZE_LOW_LOW);

    for (int i = 0; i < SIZE_LOW_LOW; i++) {
        for (int j = 0; j < SIZE_LOW_LOW; j++) {
            std::cout << *(*(nums2 + i) + j) << std::endl;
        }
        if (i == SIZE_LOW_LOW - 1) {
            std::cout << "======================" << std::endl;
            }
    }

    delete [] nums;

    nums = new int* [SIZE_LOW_LOW];

    for (int i = 0; i < SIZE_LOW_LOW; i++) {
        *(nums + i) = new int [SIZE_LOW_LOW];
        for (int j = 0; j < SIZE_LOW_LOW; j++) {
            *(*(nums + i) + j) = *(*(nums2 + i) + j);
        }
    }

    for (int i = 0; i < SIZE_LOW_LOW; i++) {
        for (int j = 0; j < SIZE_LOW_LOW; j++) {
            std::cout << *(*(nums + i) + j) << std::endl;
        }
        if (i == SIZE_LOW_LOW - 1) {
            std::cout << "======================" << std::endl;
            }
    }

    delete [] nums2;

    delete [] nums;

    return 0;
}

