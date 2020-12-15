#ifndef HUMAN_H
#define HUMAN_H
#include "birthday.h"
class human {
    public:
        human(int age, std::string name, birthday date);
        void setAge(int age);
        std::string getName() const;
        int getAge() const;
        void printInfo();
        ~human();
    protected:
    private:
        const int age;
        std::string name;
        birthday date;
};

#endif // HUMAN_H
