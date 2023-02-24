#include "../cppHeaders.h"
/// @brief experimenting with new keyword, constructors and destructors
class MenuItem{
    public:
        std::string _name;
        double _cals;
        MenuItem(){
            std::cout << "Menu Item constructor no args" << std::endl;
        }
        MenuItem(std::string name, double cals) 
            :   _cals(cals) , _name(name){
                std::cout << "Menu Item constructor" << std::endl;
        }
        MenuItem(std::string name){
                std::cout << "Menu Item constructor for " << name << std::endl;
        }
        void print(){std::cout << _name << " " << _cals << std::endl;}
};

class Drink : public MenuItem{
    int *Ptr;
    public:
        void getPtr(){std::cout << "Ptr: " << Ptr << " " << *Ptr << std::endl;}

        Drink(const char* name){
            int *gu = new int();
            Ptr = gu;
            *Ptr = 3;
            std::cout << "Drink constructor for " << name << std::endl;
            getPtr();
        }
        ~Drink(){
            std::cout << "Drink destructor " << std::endl;
            delete Ptr;
            getPtr();
        }
};

int main(){
    Drink Coca("coca");
    // MenuItem fries("Fries", 2839);
    // fries.print();
}