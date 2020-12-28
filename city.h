#ifndef CITY_H
#define CITY_H
#include "building.h"
class city {
    public:
        city(unsigned int square, std::string name, building *build1);
        ~city();
        void printInfo();
    protected:
    private:
        unsigned int square;
        std::string name;
        building build1;
        friend void aboutMen(human &human1);
};

<<<<<<< HEAD
=======
city::city(unsigned int _square, std::string _name, building *_build1) : square(_square), name(_name), build1(*_build1) {
    std::cout << "Created" << std::endl;
}

void city::printInfo() {
    std::cout << "Square: " << this->square << std::endl;
    std::cout << "Name country: " << (*this).name << std::endl;
    build1.printInfo();
}

city::~city() {
    std::cout << "Destroyed" << std::endl;
}
>>>>>>> edae2ff31295e7674aead6752619370dc778c3e2

#endif // !CITY_H