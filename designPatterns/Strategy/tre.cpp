#include "../../cppHeaders.h"

class IQuackBehaviour{
    public:
        virtual void quack() = 0;
};

class LoudQuacking : public IQuackBehaviour{
    public:
        void quack() override{
            std::cout << "QUAAAAACKKK!!.\n";
        }
};

class CrokedQuacking : public IQuackBehaviour{
    public:
        void quack() override{
            std::cout << "Q   A   K\n  U  C \n";
        }
};

class IFlyBehaviour{
    public:
        virtual void fly() = 0;
};

class SimpleFlying : public IFlyBehaviour{
    public:
        void fly() override{
            std::cout << "Simple Flying.\n";
        }
};

class NoFlying : public IFlyBehaviour{
    public:
        void fly() override{
            std::cout << "No Flying.\n";
        }
};

class Duck{
        IQuackBehaviour *_quack;
        IFlyBehaviour *_fly;
    public:
        Duck(IQuackBehaviour *quack, IFlyBehaviour *fly) : _quack(quack) , _fly(fly){}
        void Fly(){return this->_fly->fly();}
        void Quack(){return this->_quack->quack();}

};

int main(){
    Duck *quacky;
    Duck *kim;
    LoudQuacking lQ;
    CrokedQuacking kQ;
    SimpleFlying sF;
    NoFlying nF; 
    quacky = new Duck(&lQ, &nF);
    kim = new Duck(&kQ, &sF); 
    quacky->Fly();
    quacky->Quack();
    kim->Fly();
    kim->Quack();
}