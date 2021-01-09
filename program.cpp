#include <iostream>
#include <cmath>
// #include <string>
#include <string.h>
#include <limits>

#define COUNT 3
class Cable {
    std::string color;
    int length;
    char** types;
    float price;
    int LENGTH = COUNT;
public:
    Cable() {
        std::cout << "Empty constructor has been called - " << this << std::endl;
        this->types = nullptr;
    }
    Cable(int length, float price) {
        char** types = new char*[LENGTH];
        for (int i = 0; i < LENGTH; i++) {
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
        color = "white"; // default
    }
    Cable(const Cable& cable) {
        std::cout << "The copy constructor has been called - " << this << std::endl;
        char** types = new char*[LENGTH];
        for (int i = 0; i < LENGTH; i++) {
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
        this->types = new char*[LENGTH];
        for (int i = 0; i < LENGTH; i++) {
            types[i] = cable.types[i];
        }
        this->color = cable.color;
        this->length = cable.length;
        this->price = cable.price;
        
        return *this;
    }
    bool operator == (const Cable& cable) {
        if (this->length == cable.length && this->price == cable.price && this->color == cable.color) {
            for (int i = 0; i < LENGTH; i++) {
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
            for (int i = 0; i < LENGTH; i++) {
                if (this->types[i] != cable.types[i]) {
                    return true;
                }
            }
            return false;
        } else {
            return true;
        }
    }
    Cable& operator ++() {
        this->length++;
        this->price++;
        return *this;
    }
    Cable& operator ++(int i) {
        this->length++;
        this->price++;
        return *this;
    }
    Cable& operator --() {
        char** NewTypes = new char*[--LENGTH];
        for (int i = 0; i < LENGTH; i++) {
            NewTypes[i] = this->types[i];
        }
        this->types = new char*[LENGTH];
        for (int i = 0; i < LENGTH; i++) {
            this->types[i] = NewTypes[i];
        }
        delete[] NewTypes;
        NewTypes = nullptr;
        this->length--;
        this->price--;
        return *this;
    }
    Cable& operator --(int i) {
        char** NewTypes = new char*[--LENGTH];
        for (int i = 0; i < LENGTH; i++) {
            NewTypes[i] = this->types[i];
        }
        this->types = new char*[LENGTH];
        for (int i = 0; i < LENGTH; i++) {
            this->types[i] = NewTypes[i];
        }
        delete[] NewTypes;
        NewTypes = nullptr;
        this->length--;
        this->price--;
        return *this;
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
        return this->x == point.x && this->y == point.y;
    }
    bool operator != (const Point& point) {
        return !(this->x == point.x && this->y == point.y);
    }
};

class String {
    char* str;
public:
    String() {
        str = nullptr;
        std::cout << "Empty constructor has been called - " << this << std::endl;
        str = new char[1];
        str = "\0";
    }
    String(char* str) {
        std::cout << "Constructor has been called - " << this << std::endl;
        int length = strlen(str);
        this->str = new char[length];
        for (int i = 0; i < length; i++) {
            this->str[i] = str[i];
        }
    }
    String(const String& string) {
        std::cout << "Copy constructor has been called - " << this << std::endl;
        int length = strlen(string.str);
        this->str = new char[length];
        for (int i = 0; i < length; i++) {
            this->str[i] = string.str[i];
        }
    }
    ~String() {
        std::cout << "Destructor has been called - " << this << std::endl;
        if (this->str != nullptr) {
            delete[] str;
            this->str = nullptr;
        }
    }
    void printInfo() {
        std::cout << str << std::endl;
    }
    String operator + (const String& string) {
        String str;
        int len1 = strlen(this->str);
        int len2 = strlen(string.str);
        str.str = new char[len1 + len2 + 1];
        int i = 0;
        for (; i < len1; i++) {
            str.str[i] = this->str[i];
        }
        for (int j = 0; i < len1 + len2; i++, j++) {
            str.str[i] = string.str[j];
        }
        str.str[len1 + len2] = '\0';
        return str;
    }
    String& operator = (const String& string) {
        if (this->str != nullptr) {
            this->str = nullptr;
        }
        int length = strlen(string.str);
        this->str = new char[length];
        for (int i = 0; i < length; i++) {
            this->str[i] = string.str[i];
        }
        return *this;
    }
};

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(static_cast<int>(time(NULL)));
    
    // String str = "Nikita";
    // String str2;
    // str2 = str;

    // str.printInfo();
    // std::cout << std::endl;
    // str2.printInfo();

    // String str3 = str + str2;
    // str3.printInfo();

    Cable cable1(19, 51.55);
    cable1.printInfo(0);
    std::cout << std::endl;
    cable1++;

    Cable cable2;
    cable2 = cable1;

    cable1.printInfo(0);
    std::cout << std::endl;
    cable2.printInfo(0);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    --cable1;
    cable1.printInfo(0);
    cable1.printInfo(1);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    cable1--;
    cable1.printInfo(0);
    cable1.printInfo(1);

    return 0;
}

/*

Constructor has been called - 0x7ffcd89cf0b0
Function 'printInfo' has been called for object - 0x7ffcd89cf0b0
Type of cable - Type-C  Color - white
Price per piece - 51.55 His length - 19

Empty constructor has been called - 0x7ffcd89cf070
Function 'printInfo' has been called for object - 0x7ffcd89cf0b0
Type of cable - Type-C  Color - white
Price per piece - 52.55 His length - 20

Function 'printInfo' has been called for object - 0x7ffcd89cf070
Type of cable - Type-C  Color - white
Price per piece - 52.55 His length - 20



Function 'printInfo' has been called for object - 0x7ffcd89cf0b0
Type of cable - Type-C  Color - white
Price per piece - 51.55 His length - 19
Function 'printInfo' has been called for object - 0x7ffcd89cf0b0
Type of cable - Mini-B  Color - white
Price per piece - 51.55 His length - 19



Function 'printInfo' has been called for object - 0x7ffcd89cf0b0
Type of cable - Type-C  Color - white
Price per piece - 50.55 His length - 18
Function 'printInfo' has been called for object - 0x7ffcd89cf0b0
Type of cable - �ދ      <V      Color - white
Price per piece - 50.55 His length - 18
Destructor has been called - 0x7ffcd89cf070
Destructor has been called - 0x7ffcd89cf0b0

*/
