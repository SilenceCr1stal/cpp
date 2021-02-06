#include <iostream>
#include <cmath>
// #include <string>
#include <string.h>
#include <limits>

#define COUNT 3

class Point;

class String;
class Cable {
    std::string color;
    int length;
    char** types;
    float price;
    int LENGTH = COUNT;
    unsigned int id;
    static int count;
public:
    Cable() {
        std::cout << "Empty constructor has been called - " << this << std::endl;
        this->types = nullptr;
        count++;
        this->id = count;
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
        count++;
        this->id = count;
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
        count++;
        this->id = count;
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
    static int getCount() {
        return count;
    }
    static void changeCable(Cable& cable, char* type, const int index);
    int getId() {
        return this->id;
    }
    void printInfo(int type) {
        std::cout << "Function \'printInfo\' has been called for object - " << this << std::endl;
        std::cout << "Type of cable - " << this->types[type] << "\tColor - " << this->color << std::endl;
        std::cout << "Price per piece - " << this->price << "\tHis length - " << this->length << std::endl;
    }
    void takePoint(const Point& point);
    Cable& operator = (const Cable& cable);
    bool operator == (const Cable& cable);
    bool operator != (const Cable& cable);
    Cable& operator ++();
    Cable& operator ++(int);
    Cable& operator --();
    Cable& operator --(int);
};

void Cable::changeCable(Cable& cable, char* type, const int index) {
    cable.types[index] = type;
}

int Cable::count = 0;

Cable& Cable::operator = (const Cable& cable) {
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
bool Cable::operator == (const Cable& cable) {
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
bool Cable::operator != (const Cable& cable) {
    return !(Cable::operator==(cable));
}
Cable& Cable::operator ++() {
        this->length++;
        this->price++;
        return *this;
    }
Cable& Cable::operator++(int) {
    return Cable::operator++();
}
Cable& Cable::operator --() {
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
Cable& Cable::operator --(int) {
    return Cable::operator--();
}

class String;

class Point {
    int x;
    int y;

    friend void Cable::takePoint(const Point& point);
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
    char* getString(const String& string);
    bool operator == (const Point& point) {
        return this->x == point.x && this->y == point.y;
    }
    bool operator != (const Point& point) {
        return !(this->x == point.x && this->y == point.y);
    }
};

void Cable::takePoint(const Point& point) {
    std::cout << "x = " << point.x << "\ty = " << point.y << std::endl;
}

class String {
    char* str;
    int size;

    friend Point; // you can do it one way
    friend char* Point::getString(const String& string); // or another
public:
    String() {
        str = nullptr;
        std::cout << "Empty constructor has been called - " << this << std::endl;
        this->size = 0;
    }
    String(char* str) {
        std::cout << "Constructor has been called - " << this << std::endl;
        this->size = strlen(str);
        this->str = new char[this->size + 1];
        for (int i = 0; i < this->size; i++) {
            this->str[i] = str[i];
        }
        this->str[this->size] = '\0';
    }
    String(const String& string) {
        std::cout << "Copy constructor has been called - " << this << std::endl;
        this->size = strlen(string.str);
        this->str = new char[this->size];
        for (int i = 0; i < this->size; i++) {
            this->str[i] = string.str[i];
        }
    }
    String(String&& string) {
        this->size = string.size;
        this->str = string.str;
        string.str = nullptr;
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
    int length() {
        return size;
    }
    String operator + (const String& string) {
        String str;
        int len1 = strlen(this->str);
        int len2 = strlen(string.str);
        str.size = len1 + len2;
        str.str = new char[str.size + 1];
        int i = 0;
        for (; i < len1; i++) {
            str.str[i] = this->str[i];
        }
        for (int j = 0; i < str.size; i++, j++) {
            str.str[i] = string.str[j];
        }
        str.str[str.size] = '\0';
        return str;
    }
    String& operator = (const String& string) {
        if (this->str != nullptr) {
            this->str = nullptr;
        }
        this->size = strlen(string.str);
        this->str = new char[this->size + 1];
        for (int i = 0; i < this->size; i++) {
            this->str[i] = string.str[i];
        }
        this->str[this->size] = '\0';
        return *this;
    }
    bool operator ==(const String& string) {
        if (this->size != string.size) {
            return false;
        }
        for (int i = 0; i < this->size; i++) {
            if (this->str[i] != string.str[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator !=(const String& string) {
        return !(this->operator==(string));
    }
    char& operator [] (int index) {
        return this->str[index];
    }
    // friend std::ostream& operator << (std::ostream& out, const String& string);
};

// std::ostream& String::operator << (std::ostream& out, const String& string) {
//     return out << string.str;
// }

char* Point::getString(const String& string) {
    return string.str;
}

class Image {

    const static int countPixel = 5;

    class Pixel {
        int r;
        int g;
        int b;
    public:
        Pixel() {
            r = g = b = 0;
        }
        Pixel(int r, int g, int b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        std::string getInfo() {
            return "structure of a pixel: r = " + std::to_string(r) + ", g = " 
                + std::to_string(g) + ", b = " + std::to_string(b);
        }
    };

    Pixel *pixel = new Pixel[countPixel];
    
public:
    Image() {
        std::cout << "Image has been created - " << this << std::endl;
    }
    void initializePixel() {
        for (int i = 0; i < countPixel; i++) {
            pixel[i] = Pixel(rand() % 256, rand() % 256, rand() % 256);
        }
    }
    void printInfo() {
        for (int i = 0; i < countPixel; i++) {
            std::cout << pixel[i].getInfo() << std::endl;
        }
    }
    
};

class A {
    int a = 1;
    int getA() {
        return a;
    }
public:
    int b = 2;
    int getB() {
        return b;
    }
protected:
    int c = 3;
    int getC() {
        return c;
    }
};

class B : private A {
    int d = 4;
public:
    int e = c;
protected:
    int f = d;
};

class C : protected B {
    int g = e;
public:
    int h = f;
protected:
    int i = f;
};

class D : private C {
    int j = f;
public:
    int k = e;
protected:
    int s = i;
};

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    srand(static_cast<int>(time(NULL)));
    
    

    return 0;
}

/*



*/
