#include <iostream>
#include <string.h>
#include "human.h"
using namespace std;

human::human(int a, string _name) {
    cout << "Created" << endl;
    human::setAge(a);
    name = _name;
}

string human::getName() const {
    return name;
}

void human::setAge(int a) {
    human::age = a;
}

int human::getAge() const {
    return human::age;
}

human::~human() {
    cout << "Destroyed" << endl;
}

int main(int argc, char **argv) {
    const human human1(17, "Artem"); // Created
    cout << human1.getName() << endl; // Artem
    const human *p = &human1;
    cout << p->getAge() << endl; // 17
    return 0; // Destroyed
}
