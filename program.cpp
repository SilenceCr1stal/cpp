#include <iostream>
#include <string.h>
#include <time.h>
#include "human.h"
#include "birthday.h"
using namespace std;

human::human(int a, string _name, birthday _date) : age(a), name(_name), date(_date) {
    cout << "Created" << endl;
}

string human::getName() const {
    return name;
}

void human::printInfo() {
    cout << name << endl;
    date.printDate();
}

int human::getAge() const {
    return age;
}

human::~human() {
    cout << "Destroyed" << endl;
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    cout << "date of death:" << asctime(timeinfo) << endl;
}


birthday::birthday(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

void birthday::printDate() {
    cout << day << "/" << month << "/" << year << endl;
}

birthday::~birthday() {}


int main(int argc, char **argv) {
    const birthday *date = new birthday(31, 12, 2000);
    human *human1 = new human(19, "Artem", *date);
    human1->printInfo();
    delete date;
    delete human1;
}

/*
Created
Artem
31/12/2000
Destroyed
date of death:Fri Nov  6 03:07:42 2020
*/