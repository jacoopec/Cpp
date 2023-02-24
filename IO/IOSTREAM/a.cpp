#include "includes.h"

int main(){
    char buf[10];
    std::cout << "Enter 10 chars\n";
    std::cin >> std::setw(10) >> buf;
}