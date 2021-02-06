#include <iostream>
#include <cmath>
// #include <string>
#include <string.h>
#include <limits>

#define COUNT 3
#define DEFAULT_COLOR "white"
class Cable {
    std::string color;
    int length;
    char** types;
    float price;
    int LENGTH = COUNT;

    friend void changeLength(Cable& cable, const int value);
public:
    Cable() {
        std::cout << "Empty constructor has been called - " << this << std::endl;
        this->types = nullptr;
        this->length = NULL;
        this->price = NULL;
        this->color = DEFAULT_COLOR;
    }
    Cable(int length) {
        this->types = nullptr;
        this->length = length;
        this->price = NULL;
        this->color = DEFAULT_COLOR;
    }
    Cable(int length, float price);
    Cable(const Cable& cable);
    ~Cable() {
        std::cout << "Destructor has been called - " << this << std::endl;
        if (this->types != nullptr) {
            delete[] this->types;
            this->types = nullptr;
        }
    }
    void SetColor(const std::string color) {
        this->color = color;
    }
    std::string GetColor() {
        return this->color;
    }
    void printInfo() {
        std::cout << "Function \'printInfo\' has been called for object - " << this << std::endl;
        std::cout << "Color - " << this->color << std::endl;
        std::cout << "Price per piece - " << this->price << "\tHis length - " << this->length << std::endl;
    }
    void printInfo(const short type) {
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
    Cable& operator ++(int) {
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
    Cable& operator --(int) {
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
    char*& operator [] (int index) {
        return this->types[index];
    }

};

Cable::Cable(int length, float price) {
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
    color = DEFAULT_COLOR;
}

Cable::Cable(const Cable& cable) {
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

void changeLength(Cable& cable, const int value) {
    cable.length = value;
}

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
    char operator [] (int i) {
        return this->str[i];
    }
};

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(static_cast<int>(time(NULL)));
    
    Cable cable1 = 15;
    cable1.printInfo();
    changeLength(cable1, 18);
    cable1.printInfo();

    return 0;
}

/*



*/
