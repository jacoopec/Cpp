#include "../IOSTREAM/includes.h"

double function(double x){
    if(x < 0) throw "x minore di 0";
    return x;
}

int main(){
    std::cout << "enter a number";
    double x{};
    std::cin >> x;
    
    try{
        double b = function(x);
    } catch(const char*){
        std::cerr << "x minore di 0";
    }
}