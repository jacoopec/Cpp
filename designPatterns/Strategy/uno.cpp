#include "../../cppHeaders.h"

class DrinkBehavior{
    public:
        virtual void drink() = 0;
};

class DrinkWithGlass : public DrinkBehavior{
    public:
        void drink() override {
            std::cout << "I'm drinking with a glass" << std::endl;
        }
};

class DrinkFromTheBottle : public DrinkBehavior{
    public:
        void drink() override{
            std::cout << "I'm drinking from the bottle." << std::endl;
        }
};

//-------------------------------
class EatBehavior{
    public:
        virtual void eat() = 0;
};

class EatWithFork : public EatBehavior{
    public:
        void eat() override{ std::cout << "Eating with fork." << std::endl;}
};

class EatWithHand : public EatBehavior{
    public:
        void eat() override{ std::cout << "Eating with my hands." << std::endl;}
};

//-------------------------------
class Man{
    public:
        DrinkBehavior *_one;
        EatBehavior *_two;

        Man(DrinkBehavior *one, EatBehavior *two){
            this->_one = one;
            this->_two = two;
        }

        void Eat(){
            this->_two->eat();
        }

        void Drink(){
            _one->drink();
        }
};

//----------------------------------


int main(){
    EatWithFork forkEat;
    EatWithHand handEat;
    DrinkWithGlass glassDrink;
    DrinkFromTheBottle bottleDrink;
    Man john = Man(&glassDrink, &handEat);
    john.Drink();
    john.Eat();
}