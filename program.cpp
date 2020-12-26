#include <iostream>
#include <string>
#include <time.h>

#define SIZE 5
#define SIZE_LOW 4
#define SIZE_LOW_LOW 3

void FillArray(int* array, const int size) { // fill an array the some random numbers
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void ShowArray(int* array, const int size) { // show an array in the console
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
        if (i == size - 1) {
            std::cout << std::endl;
        }
    }
}

void AddNumArray(int*& arr, int& size, const int value) { // add a number
    int* NewArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        NewArr[i] = arr[i];
    }

    NewArr[size++] = value;

    delete [] arr;

    // std::cout << *&NewArr << " " << *(NewArr + 0) << std::endl;
    // std::cout << (NewArr + 0) << std::endl << std::endl;

    arr = NewArr;
}

void RemoveNumArray(int*& array, int& size, int value) { // remove any number from an array
    if (value <= size) {
        size--;
    }

    int* arr = new int [size];

    value--;

    int j = 0;

    for (int i = 0; i < size; i++) {

        if (i == value) {
            arr[i] = array[++j];
            j++;
        } else {
            arr[i] = array[j];
            j++;
        }
    }
    
    delete [] array;

    array = arr;
}

int main(int argc, char **argv) {

    srand(time(NULL));

    int size = 5;

    int* nums = new int[size];

    FillArray(nums, size);

    ShowArray(nums, size);

    std::cout << *&nums << " " << &nums[0] << std::endl;
    std::cout << (nums + 0) << " " << *(nums + 0) << std::endl << std::endl;

    AddNumArray(nums, size, 17);
    
    std::cout << *&nums << " " << *(nums + 0) << std::endl;
    std::cout << (nums + 0) << std::endl << std::endl << std::endl;

    int* age = new int [size];

    FillArray(age, size);

    ShowArray(age, size); // 88 35 7 71 57 14

    // int& linkAge = age[0];

    // std::cout << linkAge << " " << &linkAge << " " << &age << " " << *(&age + 0) << " " << &age[1] << std::endl; 

    RemoveNumArray(age, size, 2);

    ShowArray(age, size); // 88 7 71 57 14

    AddNumArray(age, size, 17);

    ShowArray(age, size); // 88 7 71 57 14 17

    RemoveNumArray(age, size, 4);

    ShowArray(age, size); // 88 7 71 14 17
    
    RemoveNumArray(age, size, 1);

    ShowArray(age, size); // 7 71 14 17

    AddNumArray(age, size, 28);

    ShowArray(age, size); // 7 71 14 17 28

    return 0;
}
