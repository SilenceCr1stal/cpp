#ifndef HUMAN_H
#define HUMAN_H
#include "birthday.h"

class human {
    public:
        human(std::string name, const birthday *date);
        int getAge() const;
        std::string getName() const;
        void printInfo();
        void dateDeath();
    protected:
    private:
        unsigned short int age;
        std::string name;
        birthday date;
        friend void checkAge(human &human1);
};

#endif // !HUMAN_H
