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

<<<<<<< HEAD
=======
human::human(std::string _name, const birthday *_date) : name(_name), date(*_date) {}

void human::printInfo() {
    std::cout << name << std::endl;
    date.printDate();
}

int human::getAge() const {
    return age;
}

std::string human::getName() const {
    return name;
}

void checkAge(human &human1) {
    human1.age = 18;
}

void human::dateDeath() {
    time_t rawtime;
    struct tm *timeinfo;

    timeinfo = localtime(&rawtime);
    std::cout << "date of death: " << asctime(timeinfo) << std::endl;
}
>>>>>>> edae2ff31295e7674aead6752619370dc778c3e2

#endif // !HUMAN_H
