#ifndef HUMAN_H
#define HUMAN_H
class human {
    public:
        human(int a, std::string name);
        void setAge(int a);
        std::string getName() const;
        int getAge() const;
        ~human();
    protected:
    private:
        mutable int age;
        std::string name;
};

#endif // HUMAN_H
