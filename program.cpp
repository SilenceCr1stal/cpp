#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <limits>

#define COUNT 3
class Cable {
    std::string color;
    int length;
    char** types;
    float price;
public:
    Cable() {
        std::cout << "Empty constructor has been called - " << this << std::endl;
    }
    Cable(int length, float price) {
        char** types = new char*[COUNT];
        for (int i = 0; i < COUNT; i++) {
            types[i] = "Type-C";
            if (i == 1) {
                types[i] = "Mini-B";
            } else if (i == 2) {
                types[i] = "Type-A";
            }
        }
        std::cout << "Constructor has been called - " << this << std::endl;
        this->length = length;
        this->types = types;
        this->price = price;
    }
    Cable(const Cable& cable) {
        std::cout << "The copy constructor has been called - " << this << std::endl;
        char** types = new char*[COUNT];
        for (int i = 0; i < COUNT; i++) {
            types[i] = "Type-A";
            if (i == 1) {
                types[i] = "Type-C";
            } else if (i == 2) {
                types[i] = "Mini-B";
            }
        }
        this->types = types;
        this->length = cable.length << 1;
        this->price = cable.price / 3;
    }
    ~Cable() {
        std::cout << "Destructor has been called - " << this << std::endl;
        // DeleteArray(this->types);
        delete[] this->types;
        this->types = nullptr;
    }
    void SetColor(std::string color) {
        this->color = color;
    }
    std::string GetColor() {
        return this->color;
    }
    void printInfo(int type) {
        std::cout << "Function \'printInfo\' has been called for object - " << this << std::endl;
        std::cout << "Type of cable - " << this->types[type] << "\tColor - " << this->color << std::endl;
        std::cout << "Price per piece - " << this->price << "\tHis length - " << this->length << std::endl;
    }
    // void DeleteArray(char** types) {
    //     for (int i = 0; i < COUNT; i++) {
    //         std::cout << types[i][i] << std::endl;
    //         delete[] types[i];
    //     }
    // }
};

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(static_cast<int>(time(NULL)));
    

    Cable cable1(20, 150.75);
    std::cout << std::endl;
    cable1.SetColor("white");
    cable1.printInfo(2);
    std::cout << std::endl;
    Cable cable2(cable1);
    std::cout << std::endl;
    cable2.SetColor("black");
    cable2.printInfo(1);
    std::cout << std::endl;

    return 0;
}
