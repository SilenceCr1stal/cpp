#include <iostream>
#include <string.h>
#include <ctime>
#include "city.h"
#include "building.h"
#include "human.h"
#include "birthday.h"
using namespace std;

int main(int argc, char **argv) {
    const birthday *date = new birthday(29, 12, 2002);

    human *human1 = new human("Nikita", date);

    building *build1 = new building(1000, human1);

    city *town = new city(3800000, "USA", build1);

    town->printInfo();

    cout << endl;

    checkAge(*human1);
    cout << (*human1).getAge() << endl;

    delete town;
    return 0;
}
