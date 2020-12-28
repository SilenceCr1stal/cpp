#include <iostream>
#include <string.h>
#include <ctime>
#include "city.h"
#include "building.h"
#include "human.h"
#include "birthday.h"
using namespace std;

city::city(unsigned int _square, string _name, building *_build1) : square(_square), name(_name), build1(*_build1) {
    cout << "Created" << endl;
}

void city::printInfo() {
    cout << "Square: " << square << endl;
    build1.printInfo();
}

city::~city() {
    cout << "Destroyed" << endl;
}

building::building(int _height, human *_human1) : human1(*_human1) {
    building::setHeight(_height);
}

void building::setHeight(int _height) {
    height = _height;
}

void building::printInfo() {
    cout << "Height of building: " << height << endl;
    human1.printInfo();
}

human::human(string _name, const birthday *_date) : name(_name), date(*_date) {}

void human::printInfo() {
    cout << name << endl;
    date.printDate();
}

void human::dateDeath() {
    time_t rawtime;
    struct tm *timeinfo;

    timeinfo = localtime(&rawtime);
    cout << "date of death: " << asctime(timeinfo) << endl;
}

birthday::birthday(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

void birthday::printDate() {
    cout << day << "/" << month << "/" << year << endl;
}

int main(int argc, char **argv) {
    const birthday *date = new birthday(29, 12, 2002);

    human *human1 = new human("Nikita", date);

    building *build1 = new building(1000, human1);

    city *town = new city(3800000, "USA", build1);

    town->printInfo();
    delete town;
    delete build1;
    delete human1;
    delete date;

    return 0;
}
