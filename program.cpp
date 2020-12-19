#include <iostream>
#include <string>
#include <time.h>
#define SIZE 5
#define SIZE_COL 4

int main(int argc, char** argv) {
    srand(time(NULL));
    // int nums[] = {17, 87, 54, 49, 16, 31, 70};


    int **ages = new int* [SIZE];

    for (int i = 0; i < SIZE; i++) {
        *(ages + i) = new int[SIZE_COL];
        for (int j = 0; j < SIZE_COL; j++) {
            *(*(ages + i) + j) = rand() % 10;
            std::cout << *(*(ages + i) + j) << "\t";
        }
        std::cout << std::endl;
        if (i == SIZE_COL) {
                delete [] *(ages + i);
            }
    }

    delete [] ages;

    return 0;
}
