#include "headers.h"

class Heating{
    virtual void Heat() = 0;
};

class Beverage : public Heating{
    double mCost;
    double mQuantity;
    double mTemperature;
    public:
        void Heat(double howMuch){ mTemperature += howMuch;}
};

class Coffee : public Beverage{

};

class Chocolate : public Beverage{

};

class Milk : public Beverage{

};

class Cappuccino{

};

int main(){
    std::string s;
    s.append("h");
    s.reserve(23);
    s.insert(s.begin()+1,'g');
    std::cout << s << " s.at(0)"  << s.at(0) <<  " s.size()"  << s.capacity() <<  " s.begin()"  << *s.begin() << std::endl;
    void* r = malloc(4);
    *(int*)r = 3;
    free(r);
}