#include "Cat.h"

Cat::Cat(int y, std::string n_) : year(y) ,  name(n_) {PrintInfo();};
Cat::Cat(){};
void Cat::PrintInfo(){std::cout << "Composition uses objects of other classes inside a class" << std::endl;};

void Cat::eat(){
    std::cout << "I eat what a cat eats." << std::endl;
}
void Cat::sleep(){
    std::cout << "I sleep as a cat." << std::endl;
}
void Cat::drink(){
    std::cout << "I drink as a cat." << std::endl;
}
void Cat::washing(){
    std::cout << "I wash myself like a cat." << std::endl;
}