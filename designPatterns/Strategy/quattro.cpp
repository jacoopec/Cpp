#include "../../cppHeaders.h"



class Reparable{
    virtual void repair() = 0; 
};

class Refillable{
    virtual void refill() = 0;
};
//-------------------------------------------------------
class FuelRefill : public Refillable{
    void refill(){
        std::cout << "Fuel refill" << std::endl;
    }
};

class AnotherRefill : public Refillable{
    void refill(){
        std::cout << "Another refill" << std::endl;
    }
};
//--------------------------------------------------------
class HumanReparable : public Reparable{
    void repair(){
        std::cout << "Repaired by human" << std::endl;
    }
};

class SelfReparable : public Reparable{
    void repair(){
        std::cout << "Self repaired." << std::endl;
    }
};
//--------------------------------------------------------
class Soldier{
    public:
        std::string _name;
        Refillable* _rf;
        Reparable* _rp;
        Soldier(std::string _name, Refillable* _rf, Reparable* _rp){}

};

class Robot : public Soldier{
    int _number;
    public:
        Robot(std::string name, int serialNum, Refillable* _rf, Reparable* _rp) 
            : Soldier(name, _rf, _rp ) , _number(serialNum){}
};

class Archer : public Soldier{
    const char* _arch;
    public:
        Archer(std::string name, int serialNum, Refillable* _rf, Reparable* _rp, const char* arch) 
            : Soldier(name, _rf, _rp ) , _arch(arch){}
};

int main(){
    HumanReparable hR;
    SelfReparable sR;
    FuelRefill fR;
    AnotherRefill aR;
    Robot camion("oji", 23, &fR, &hR);
    camion._rf = &aR;
}