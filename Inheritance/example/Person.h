#include <string>
#include "Cat.h"
#include "Animal.h"

class Person : public Animal , public Wash{
    std::string name;
    Cat fCat;
    public:
        Person(){};
        void washing(){ std::cout << "I wash myself like a person." << std::endl;} 
        Person(std::string name_, Cat fCat_) : fCat(fCat_) , name(name_){ std::cout << "Person born" << std::endl;};
        ~Person(){std::cout << "Person dies" << std::endl;}
};