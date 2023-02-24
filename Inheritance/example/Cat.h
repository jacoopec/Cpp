#ifndef CAT
#define CAT
#include <string>
#include <iostream>
#include "Animal.h"
//comment
class Cat : public Animal{
    int year;
    std::string name;
    public:
        Cat(int y, std::string n_);
        Cat();
        void PrintInfo();
        friend void frienFunctionCat(Cat& c);
        void eat() override;
        void sleep() override;
        void drink() override;
        void washing();
};
#endif