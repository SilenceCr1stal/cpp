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


#endif // !CITY_H