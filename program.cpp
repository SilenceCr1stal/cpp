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

    std::cout << arr << " " << *arr << " " << *&arr << " " << " - it's old array" << std::endl;

    std::cout << NewArr << " " << *NewArr << " " << *&NewArr << " " << " - it's new array" << std::endl;

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
            arr[i] = *(array + ++j);
            j++;
        } else {
            arr[i] = *(array + j);
            j++;
        }
    }
    
    delete [] array;

    array = arr;

}

void FillTwoArray(int** array, const int size1, const int size2) {
    for (int i = 0; i < size1; i++) {
        array[i] = new int [size2];
        for (int j = 0; j < size2; j++) {
            array[i][j] = rand() % 100;
        }
    }
}

void ShowTwoArray(int** array, const int size1, const int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            std::cout << array[i][j] << " ";
            if (j == size2 - 1) {
                std::cout << std::endl;
            }
        }
    }
}

void DeleteArrays(int** array, const int size) {
    for (int i = 0; i < size; i++) {
        delete [] array[i];
    }
}

int main(int argc, char **argv) {

    srand(time(NULL));

    int size = 5;

    // int* nums = new int[size];

    // FillArray(nums, size);

    // ShowArray(nums, size);

    // std::cout << *&nums << " " << &nums[0] << std::endl;
    // std::cout << (nums + 0) << " " << *(nums + 0) << std::endl << std::endl;

    // AddNumArray(nums, size, 17);
    
    // std::cout << *&nums << " " << *(nums + 0) << std::endl;
    // std::cout << (nums + 0) << std::endl << std::endl << std::endl;

    int* age = new int [size];

    FillArray(age, size);

    ShowArray(age, size);

    std::cout << age << " " << *age << " " << &age << " " << *(&age + 0) << " " << *(age + 0) << " " << &age[0] << std::endl << std::endl; 


    AddNumArray(age, size, 17);

    RemoveNumArray(age, size, 3);

    ShowArray(age, size);

    std::cout << age << " " << *age << " " << &age << " " << *(&age + 0) << " " << *(age + 0) << " " << &age[0] << std::endl; 

    int** nums = new int* [size - 2];

    FillTwoArray(nums, size - 2, size);

    ShowTwoArray(nums, size - 2, size);

    DeleteArrays(nums, size - 2);
    delete [] nums;

    return 0;
}
