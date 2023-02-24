#ifndef ANIM
#define ANIM
#include <iostream>
#include "Wash.h"

class Animal{
    public:
        virtual void eat();
        virtual void sleep();
        virtual void drink();
        // void washing();
        Animal();
        ~Animal();
};

#endif