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

#endif // !BIRTHDAY_H