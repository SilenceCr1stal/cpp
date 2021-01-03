#include <iostream>
#include <cmath>
#include <string>
#include <string.h>

void FillArray(int*** array, const int size1, const int size2, const int size3) {
    for (short int i = 0; i < size1; i++) {
        array[i] = new int* [size2];
        for (short int j = 0; j < size2; j++) {
            *(*(array + i) + j) = new int [size3];
            for (short int k = 0; k < size3; k++) {
                *(*(*(array + i) + j) + k) = rand() % 100;
            }
        }
    }
}

void ShowArray(int*** array, const int size1, const int size2, const int size3) {
    for (short int i = 0; i < size1; i++) {
        for (short int j = 0; j < size2; j++) {
            for (short int k = 0; k < size3; k++) {
                if (!(k == size3 - 1)) {
                    std::cout << array[i][j][k] << "\t";
                } else if (j == size2 - 1) {
                    std::cout << array[i][j][k];
                } else {
                    std::cout << array[i][j][k] << "\t===\t";
                }
            }
            if (j == size2 - 1) {
                std::cout << std::endl;
            }
        }
    }
}

void ChangeElementArray(int***& array, const int size1, const int size2, const int size3, int value, const int position) {
    int*** NewArray = new int** [size1];
    for (short int i = 0; i < size1; i++) {
        NewArray[i] = new int* [size2];
        for (short int j = 0; j < size2; j++) {
            NewArray[i][j] = new int [size3];
            for (short int k = 0; k < size3; k++) {
                if (!(k == position)) {
                    NewArray[i][j][k] = array[i][j][k];
                } else {
                    NewArray[i][j][k] = value;
                }
            }
        }
    }

    delete [] array;

    array = NewArray;
}

void AddElementArray(int***& array, const int size1, const int size2, int& size3, int value) {
    int size = size3;
    int*** NewArray = new int** [size1];
    for (short int i = 0; i < size1; i++) {
        NewArray[i] = new int* [size2];
        for (short int j = 0; j < size2; j++) {
            NewArray[i][j] = new int [size3 + 1];
            for (short int k = 0; k < size3; k++) {
                NewArray[i][j][k] = array[i][j][k];
            }
            if (!(size3 == size + 1)) {
                NewArray[i][j][size3++] = value;
            } else {
                NewArray[i][j][size] = value;
            }
        }
    }

    delete [] array;

    array = NewArray;
}

void RemoveElementArray(int***& array, const int size1, const int size2, int& size3, int position) {
    if (position <= size3) {
        --size3;
    }
    int l = 0;
    int*** NewArray = new int** [size1];
    for (short int i = 0; i < size1; i++) {
        NewArray[i] = new int* [size2];
        for (short int j = 0; j < size2; j++) {
            NewArray[i][j] = new int [size3];
            for (short int k = 0; k < size3; k++) {
                if (!(k == position)) {
                    NewArray[i][j][k] = array[i][j][l];
                    l++;
                } else {
                    NewArray[i][j][k] = array[i][j][++l];
                    ++l;
                }
            }
            l = 0;
        }
    }

    delete [] array;

    array = NewArray;
}

void DeleteArray(int*** array, const int size1, const int size2) {
    for (short int i = 0; i < size1; i++) {
        for (short int j = 0; j < size2; j++) {
            delete [] array[i][j];
        }
        delete [] array[i];
    }
}

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int SIZE = 5, SIZE_LOW = 4, SIZE_LOW_LOW = 3;

    int*** array = new int** [SIZE];

    // int& size1 = SIZE;
    // int& size2 = SIZE_LOW;
    // int& size3 = SIZE_LOW_LOW;

    FillArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW);

    ShowArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW);

    std::cout << std::endl << SIZE_LOW_LOW << std::endl;

    // ChangeElementArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW, 17, 1);

    AddElementArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW, 17);

    ShowArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW);

    std::cout << std::endl << SIZE_LOW_LOW << std::endl;

    AddElementArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW, 28);

    ShowArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW);

    std::cout << std::endl << SIZE_LOW_LOW << std::endl;

    RemoveElementArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW, 2);

    ShowArray(array, SIZE, SIZE_LOW, SIZE_LOW_LOW);

    std::cout << std::endl << SIZE_LOW_LOW << std::endl;

    DeleteArray(array, SIZE, SIZE_LOW);
    delete [] array;

    return 0;
}
