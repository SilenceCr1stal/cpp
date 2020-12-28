#ifndef BUILDING_H
#define BUILDING_H
#include "human.h"
class building {
    public:
        building(int height, human *human1);
        void setHeight(int _height);
        void printInfo();
    protected:
    private:
        unsigned short int height;
        human human1;
    };

<<<<<<< HEAD
=======
building::building(int _height, human *_human1) : human1(*_human1) {
    building::setHeight(_height);
}

void building::setHeight(int _height) {
    height = _height;
}

void building::printInfo() {
    std::cout << "Height of building: " << height << std::endl;
    human1.printInfo();
}
>>>>>>> edae2ff31295e7674aead6752619370dc778c3e2

#endif