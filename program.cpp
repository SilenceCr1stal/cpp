#include <iostream>
#include <cmath>
#include <string>
#include <limits>

void FillArray(int* array, const int size);
class Point {
    int ArrSize;
    int* x;
    int* y;
public:
    Point(int size) {
        std::cout << "Constructor was called" << std::endl;
        x = new int[size];
        y = new int[size];
        FillArray(x, size);
        FillArray(y, size);
        ArrSize = size;
    }
    ~Point() {
        delete[] x;
        delete[] y;
        std::cout << "Destructor was called" << std::endl;
    }
    void GetX() {
        for (int i = 0; i < ArrSize; i++) {
            std::cout << x[i] << "\t";
            if (i == ArrSize - 1) {
                std::cout << std::endl;
            }
        }
    }
    void GetY() {
        for (int i = 0; i < ArrSize; i++) {
            std::cout << y[i] << "\t";
            if (i == ArrSize - 1) {
                std::cout << std::endl;
            }
        }
    }
};

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(static_cast<int>(time(NULL)));
    
    Point human(5);

    human.GetX();
    human.GetY();

    return 0;
}

void FillArray(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}