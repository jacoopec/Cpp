#include "includes.h"

int main(){
    std::string str;
    std::getline(std::cin, str);
    std::cin.ignore();
    std::cin.peek();
    std::cin.unget();
    std::cin.putback('d');
    
}