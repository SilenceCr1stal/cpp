#ifndef BIRTHDAY_H
#define BIRTHDAY_H


class birthday {
    public:
        birthday(int day, int month, int year);
        void printDate();
    protected:
    private:
        const unsigned short int day;
        const unsigned short int month;
        const unsigned int year;
};

birthday::birthday(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

void birthday::printDate() {
    std::cout << day << "/" << month << "/" << year << std::endl;
}

#endif // !BIRTHDAY_H