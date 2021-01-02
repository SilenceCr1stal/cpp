#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#define SIZE 5

void FillArray(int*** array, const int size) {
    for (short int i = 0; i < SIZE; i++) {
        array[i] = new int* [size - 1];
        for (short int j = 0; j < size - 1; j++) {
            *(*(array + i) + j) = new int [size - 1 - 1];
            for (short int k = 0; k < size - 1 - 1; k++) {
                *(*(*(array + i) + j) + k) = rand() % 100;
            }
        }
    }
}

void ShowArray(int*** array, const int size) {
    for (short int i = 0; i < size; i++) {
        for (short int j = 0; j < size - 1; j++) {
            for (short int k = 0; k < size - 1 - 1; k++) {
                if (!(k == size - 1 - 1 - 1)) {
                    std::cout << array[i][j][k] << "\t";
                } else if (j == size - 1 - 1) {
                    std::cout << array[i][j][k];
                } else {
                    std::cout << array[i][j][k] << "\t===\t";
                    delete [] array[i][j];
                }
            }
            if (j == size - 1 - 1) {
                std::cout << std::endl;
                delete [] array[i];
            }
        }
    }
}

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int*** array = new int** [SIZE];

    FillArray(array, SIZE);

    ShowArray(array, SIZE);

    delete [] array;

    return 0;
}
