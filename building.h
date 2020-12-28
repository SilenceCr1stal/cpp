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


#endif