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
        this->types = nullptr;
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
        if (this->types != nullptr) {
            delete[] this->types;
            this->types = nullptr;
        }
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
    Cable& operator = (const Cable& cable) {
        if (this->types != nullptr) {
            delete[] types;
        }
        this->types = new char*[COUNT];
        for (int i = 0; i < COUNT; i++) {
            types[i] = cable.types[i];
        }
        this->color = cable.color;
        this->length = cable.length;
        this->price = cable.price;
        
        return *this;
    }
    bool operator == (const Cable& cable) {
        if (this->length == cable.length && this->price == cable.price && this->color == cable.color) {
            for (int i = 0; i < COUNT; i++) {
                if (this->types[i] != cable.types[i]) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }
    bool operator != (const Cable& cable) {
        if (this->length == cable.length && this->price == cable.price && this->color == cable.color) {
            for (int i = 0; i < COUNT; i++) {
                if (this->types[i] != cable.types[i]) {
                    return true;
                }
            }
            return false;
        } else {
            return true;
        }
    }
};

class Point {
    int x;
    int y;
public:
    Point() {
        std::cout << "Empty constructor has been called - " << this << std::endl;
    }
    Point(int x, int y) {
        std::cout << "Constructor has been called - " << this << std::endl;
        this->x = x;
        this->y = y;
    }
    ~Point() {
        std::cout << "Destructor has been called - " << this << std::endl;
    }
    void printInfo() {
        std::cout << "X = " << x << "\tY = " << y << std::endl;
    }
    bool operator == (const Point& point) {
        if (this->x == point.x && this->y == point.y) { 
            return true;
        } else {
            return false;
        }
    }
    bool operator != (const Point& point) {
        if (this->x == point.x && this->y == point.y) { 
            return false;
        } else {
            return true;
        }
    }
};

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(static_cast<int>(time(NULL)));
    
    Point a(15, 76);
    Point b(14, 76);
    Point c(15, 75);
    Point d(15, 76);

    Cable cable1(15, 55.75);
    Cable cable2(15, 55.55);
    Cable cable3 = cable1;
    Cable cable4;
    cable4 = cable2;
    Cable cable5;
    cable5 = cable1;

    bool ab = a == b; // 0
    bool ac = a == c; // 0
    bool ad = a == d; // 1
    bool bc = b == c; // 0
    bool cd = c == d; // 0
    bool da = d == a; // 1

    std::cout << ab << " " << ac << " " << ad << " " << bc << " " << cd << " " << da << std::endl;

    bool c1c2 = cable1 == cable2;
    bool c1c3 = cable1 == cable3;
    bool c1c4 = cable1 == cable4;
    bool c1c5 = cable1 == cable5;
    bool c2c1 = cable2 == cable1;
    bool c2c3 = cable2 == cable3;
    bool c2c4 = cable2 == cable4;
    bool c2c5 = cable2 == cable5;
    bool c3c1 = cable3 == cable1;
    bool c3c2 = cable3 == cable2;
    bool c3c4 = cable3 == cable4;
    bool c3c5 = cable3 == cable5;
    bool c4c1 = cable4 == cable1;
    bool c4c2 = cable4 == cable2;
    bool c4c3 = cable4 == cable3;
    bool c4c5 = cable4 == cable5;
    bool c5c1 = cable5 == cable1;
    bool c5c2 = cable5 == cable2;
    bool c5c3 = cable5 == cable3;
    bool c5c4 = cable5 == cable4;

    cable1.printInfo(1);
    std::cout << std::endl;
    cable2.printInfo(1);
    std::cout << std::endl;
    cable3.printInfo(1);
    std::cout << std::endl;
    cable4.printInfo(1);
    std::cout << std::endl;
    cable5.printInfo(1);
    std::cout << std::endl;

    std::cout << "c1c2 = " << c1c2 << "\tc1c3 = " << c1c3 << "\tc1c4 = " << c1c4 << "\tc1c5 = " << c1c5 << std::endl;
    std::cout << "c2c1 = " << c2c1 << "\tc2c3 = " << c2c3 << "\tc2c4 = " << c2c4 << "\tc2c5 = " << c2c5 << std::endl;
    std::cout << "c3c1 = " << c3c1 << "\tc3c2 = " << c3c2 << "\tc3c4 = " << c3c4 << "\tc3c5 = " << c3c5 << std::endl;
    std::cout << "c4c1 = " << c4c1 << "\tc4c2 = " << c4c2 << "\tc4c3 = " << c4c3 << "\tc4c5 = " << c4c5 << std::endl;
    std::cout << "c5c1 = " << c5c1 << "\tc5c2 = " << c5c2 << "\tc5c3 = " << c5c3 << "\tc5c4 = " << c5c4 << std::endl << std::endl;

    c1c2 = cable1 != cable2;
    c1c3 = cable1 != cable3;
    c1c4 = cable1 != cable4;
    c1c5 = cable1 != cable5;
    c2c1 = cable2 != cable1;
    c2c3 = cable2 != cable3;
    c2c4 = cable2 != cable4;
    c2c5 = cable2 != cable5;
    c3c1 = cable3 != cable1;
    c3c2 = cable3 != cable2;
    c3c4 = cable3 != cable4;
    c3c5 = cable3 != cable5;
    c4c1 = cable4 != cable1;
    c4c2 = cable4 != cable2;
    c4c3 = cable4 != cable3;
    c4c5 = cable4 != cable5;
    c5c1 = cable5 != cable1;
    c5c2 = cable5 != cable2;
    c5c3 = cable5 != cable3;
    c5c4 = cable5 != cable4;

    std::cout << "c1c2 = " << c1c2 << "\tc1c3 = " << c1c3 << "\tc1c4 = " << c1c4 << "\tc1c5 = " << c1c5 << std::endl;
    std::cout << "c2c1 = " << c2c1 << "\tc2c3 = " << c2c3 << "\tc2c4 = " << c2c4 << "\tc2c5 = " << c2c5 << std::endl;
    std::cout << "c3c1 = " << c3c1 << "\tc3c2 = " << c3c2 << "\tc3c4 = " << c3c4 << "\tc3c5 = " << c3c5 << std::endl;
    std::cout << "c4c1 = " << c4c1 << "\tc4c2 = " << c4c2 << "\tc4c3 = " << c4c3 << "\tc4c5 = " << c4c5 << std::endl;
    std::cout << "c5c1 = " << c5c1 << "\tc5c2 = " << c5c2 << "\tc5c3 = " << c5c3 << "\tc5c4 = " << c5c4 << std::endl;
    std::cout << std::endl;
    return 0;
}

/*

Constructor has been called - 0x7ffd049024bc
Constructor has been called - 0x7ffd049024b4
Constructor has been called - 0x7ffd049024ac
Constructor has been called - 0x7ffd049024a4
Constructor has been called - 0x7ffd04902460
Constructor has been called - 0x7ffd04902420
The copy constructor has been called - 0x7ffd049023e0
Empty constructor has been called - 0x7ffd049023a0
Empty constructor has been called - 0x7ffd04902360
0 0 1 0 0 1
Function 'printInfo' has been called for object - 0x7ffd04902460
Type of cable - Mini-B  Color - 
Price per piece - 55.75 His length - 15

Function 'printInfo' has been called for object - 0x7ffd04902420
Type of cable - Mini-B  Color - 
Price per piece - 55.55 His length - 15

Function 'printInfo' has been called for object - 0x7ffd049023e0
Type of cable - Type-C  Color - 
Price per piece - 18.5833       His length - 30

Function 'printInfo' has been called for object - 0x7ffd049023a0
Type of cable - Mini-B  Color - 
Price per piece - 55.55 His length - 15

Function 'printInfo' has been called for object - 0x7ffd04902360
Type of cable - Mini-B  Color - 
Price per piece - 55.75 His length - 15

c1c2 = 0        c1c3 = 0        c1c4 = 0        c1c5 = 1
c2c1 = 0        c2c3 = 0        c2c4 = 1        c2c5 = 0
c3c1 = 0        c3c2 = 0        c3c4 = 0        c3c5 = 0
c4c1 = 0        c4c2 = 1        c4c3 = 0        c4c5 = 0
c5c1 = 1        c5c2 = 0        c5c3 = 0        c5c4 = 0

c1c2 = 1        c1c3 = 1        c1c4 = 1        c1c5 = 0
c2c1 = 1        c2c3 = 1        c2c4 = 0        c2c5 = 1
c3c1 = 1        c3c2 = 1        c3c4 = 1        c3c5 = 1
c4c1 = 1        c4c2 = 0        c4c3 = 1        c4c5 = 1
c5c1 = 0        c5c2 = 1        c5c3 = 1        c5c4 = 1

Destructor has been called - 0x7ffd04902360
Destructor has been called - 0x7ffd049023a0
Destructor has been called - 0x7ffd049023e0
Destructor has been called - 0x7ffd04902420
Destructor has been called - 0x7ffd04902460
Destructor has been called - 0x7ffd049024a4
Destructor has been called - 0x7ffd049024ac
Destructor has been called - 0x7ffd049024b4
Destructor has been called - 0x7ffd049024bc

*/