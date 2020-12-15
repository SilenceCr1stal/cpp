#ifndef BIRTHDAY_H
#define BIRTHDAY_H

class birthday {
    public:
        birthday(int day, int month, int year);
        ~birthday();
        const int day;
        const int month;
        int getYear();
        void printDate();
    protected:
    private:
        const int year;
};

#endif // !BIRTHDAY_H