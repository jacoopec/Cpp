#include "Animal.h"

Animal::Animal(){std::cout << "Animal born" << std::endl;}
Animal::~Animal(){std::cout << "Animal dies" << std::endl;}
void Animal::eat(){
    std::cout << "I eat." << std::endl;
}
void Animal::sleep(){
    std::cout << "I sleep." << std::endl;
}
void Animal::drink(){
    std::cout << "I drink.S" << std::endl;
}
// void Animal::washing(){
//     std::cout << "I wash like an animal" << std::endl;
// }