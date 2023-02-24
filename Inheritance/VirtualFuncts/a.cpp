#include "../IOSTREAM/includes.h"
#include <vector>

class Base{
    int a;
    public:
        virtual void something(){std::cout <<  "Base\n";}
};

class Derived: public Base{
    int b;
    public:
        void something()override{std::cout <<  "Derived\n";}
};

class Derived2: public Base{
    int b;
    public:
        void something()override{std::cout <<  "Derived2\n";}
};

void print(std::vector<Base*> bases){
    for(auto* b : bases) b->something();
}

int main(){
    Base b;
    Derived d;
    Derived2 d2;
    Base& refBase{d};
    Base* pBase{&d};
    Base* bases[]{&b, &d, &d2};

    b.something();
    d.something();
}   