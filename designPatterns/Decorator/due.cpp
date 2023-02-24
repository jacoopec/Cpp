#include "../../cppHeaders.h"

class Beverage {
    public:
        virtual double cost() = 0;
        virtual std::string getDescription() = 0;
        virtual ~Beverage() {}
};
 
class Coffee : public Beverage {
    public:
        double cost() {
            return 3.42;
        }
        std::string getDescription() {
            return "\nThis is a Coffee";
        }
};

class CoffeeDecorator : public Beverage {
    protected:
        Beverage *m_decoratedCoffee; 
    
    public:
        CoffeeDecorator (Beverage *decoratedCoffee): 
        m_decoratedCoffee(decoratedCoffee) {}
};

class CoffeWithSambuca : public CoffeeDecorator 
{
    public:
        CoffeWithSambuca (Beverage *decoratedCoffee): 
            CoffeeDecorator(decoratedCoffee) {}
    
        double cost() {
            return m_decoratedCoffee->cost() +0.48;
        }
    
        std::string getDescription() {
            return m_decoratedCoffee->getDescription() + " con sambuca ";
        }

};

class CoffeeWithLatte : public CoffeeDecorator {
    public:
        CoffeeWithLatte (Beverage *decoratedCoffee): 
            CoffeeDecorator(decoratedCoffee) {}
    
        double cost() {
            return m_decoratedCoffee->cost() + 0.82;
        }
    
        std::string getDescription() {
            return m_decoratedCoffee->getDescription() + " con latte";
        }
};

int main(){
    Beverage *Coffee1 = new Coffee();
    std::cout << Coffee1 -> getDescription() << " It costs " << Coffee1->cost() << std::endl;

    Beverage *Coffee2 = new CoffeWithSambuca ( new Coffee());
    std::cout << Coffee2 -> getDescription() << " It costs " << Coffee2->cost() << std::endl;

    Beverage *Coffee3 = new CoffeeWithLatte ( new Coffee());
    std::cout << Coffee3 -> getDescription() << " It costs " << Coffee3->cost()<< std::endl;

    Beverage *Coffee4 = new CoffeWithSambuca (
                    new CoffeeWithLatte(new Coffee()));
    std::cout << Coffee4 -> getDescription() << " It costs " << Coffee4->cost() << std::endl;

    return 0;
}