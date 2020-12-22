#include <iostream>
#include <string>
#include <time.h>
// #define SIZE 5
#define SIZE_LOW 4
#define SIZE_LOW_LOW 3

void FillArray(int *nums, int &size) { // fill an array with some numbers
    for (int i = 0; i < size;)
    {
        *(nums + i++) = rand() % 100;
    }
}

void ShowArray(int* nums, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << *(nums + i) << " ";
        if (i == size - 1) {
            std::cout << std::endl;
        }
    }
}

void AddNumArray(int* &arr, int &size, const int value) { // add a number
    int* NewArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        NewArr[i] = arr[i];
    }

    NewArr[size++] = value;

    delete [] arr;

    arr = NewArr;
}

int main(int argc, char **argv) {

    srand(time(NULL));

    int SIZE = 5;

    int &size = SIZE;

    int* nums = new int[size];

    std::cout << *nums << " " << nums << " size = " << size << std::endl;

    FillArray(nums, size);

    ShowArray(nums, size);

    std::cout << nums[1] << " " << *(nums + 1) << " " << nums << " " << &nums << " " << " size = " << size << std::endl << std::endl << std::endl;

    AddNumArray(nums, size, 17);

    ShowArray(nums, size);

    AddNumArray(nums, size, 28);

    ShowArray(nums, size);

    delete [] nums;

    return 0;
}
