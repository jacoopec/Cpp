#include "../../cppHeaders.h"

class Beverage{
    public:
        virtual std::string getDescription() = 0;
        virtual double getCost() = 0;
};

class Caffe : public Beverage{
    public:
        std::string getDescription()override{
            return  "I'm a coffe ";
        }
        double getCost()override{
            return 1.34;
        }
};

class Tea : public Beverage{
    public:
        std::string getDescription(){
            return  "I'm a tea ";
        }
        double cost(){
            return 0.74;
        }
};

class Decorator : public Beverage{
    protected:
        Beverage *_b;
};

class Soy : public Decorator{
    public:
        Soy(Beverage *b){this->_b = b;}
        std::string getDescription() override{
            return this->_b->getDescription() + " with Soy";
        }
        double getCost()override{
            return 0.74 + this->_b->getCost();
        }

};

class Caramel : public Decorator{
    public:
        Caramel(Beverage *b){this->_b = b;}
        std::string getDescription()override{
            return this->_b->getDescription() + " with caramel";
        }
        double getCost()override{
            return 0.74 + this->_b->getCost();
        }
};


int main(){
    Caffe buono = Caffe();
    Caramel carm = Caramel(&buono);
    Soy s = Soy(&carm);
    std::cout << buono.getDescription() << buono.getCost()<< std::endl;
    std::cout << carm.getDescription() << carm.getCost() << std::endl;
    std::cout << s.getDescription() << s.getCost() << std::endl;
}