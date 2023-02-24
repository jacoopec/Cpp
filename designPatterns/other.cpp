#include "../../cppHeaders.h"
#include "../../CHeaders.h"

class ISomethingDifferent{ //INTERFACE
    public:
        virtual void doSomethingDifferent() = 0;
        virtual void sayHiDifferently() = 0;
};

class DifferentThing : public ISomethingDifferent{   //CONCRETE CLASS
    public:
        void doSomethingDifferent() override  {std::cout << "Something different Done.\n";};
        void sayHiDifferently() override  {std::cout << "Say hi differently.\n";};
};

class ISomething{  //INTERFACE
    public:
        virtual void doSomething() = 0;
        virtual void sayHi() = 0;
};

class AbstractThing: public ISomething{ //ABSTRACT CLASS
    public:
        void doSomething() override { std::cout << "Something Abstract Done.\n";}
        virtual void sayHi(){ std::cout << "Hi.\n";};
};

class Thing : public ISomething{   //CONCRETE CLASS
    ISomethingDifferent *_sD;
    public:
        Thing(){}
        Thing(ISomethingDifferent *sD){this->_sD = sD;}
        void doSomething() override { std::cout << "Something Done.\n";}
        void sayHi() override { std::cout << "Hi.\n";}
};

class FirstObj{
    public:
        void show(){std::cout << "I'm the first obj.\n";}
        void firstObjMethod(){std::cout << "I'm a method from the first obj.\n";}
};

class SecondObj{
    public:
        void show(){std::cout << "I'm the second obj.\n";}
        void secondObjMethod(){std::cout << "I'm a method from the second obj.\n";}
};

class ThirdObj{
    public:
        void show(){std::cout << "I'm the third obj.\n";}
        void thirdObjMethod(){std::cout << "I'm a method from the third obj.\n";}
};

class ComposedObj{
    FirstObj _fO;
    SecondObj _sO;
    ThirdObj _tO;
    public:
        ComposedObj(FirstObj fO, SecondObj sO, ThirdObj tO){
            this->_fO = fO;
            this->_sO = sO;
            this->_tO = tO;
        }
        
        void show(){_fO.show(); _sO.show(); _tO.show();}
        void composedMethods(){_fO.firstObjMethod(); _sO.secondObjMethod(); _tO.thirdObjMethod();}
};


int main(){
    DifferentThing *dT = new DifferentThing();

    Thing stackThing();
    Thing *pointerThing = new Thing();
    Thing stackThing2(dT);


    AbstractThing abThing();

    pointerThing->doSomething();
    pointerThing->sayHi();

    //COMPOSITION
    std::cout << "Composition\n";
    FirstObj O1;
    SecondObj O2;
    ThirdObj O3;
    ComposedObj cO(O1, O2, O3);
    cO.show();
    cO.composedMethods();
}