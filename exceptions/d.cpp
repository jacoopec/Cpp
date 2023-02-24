#include "../../cppHeaders.h"

void D()
{
    std::cout << "D started" << '\n';
    throw "joi";
    std::cout << "D ended" << '\n';
    return;
}

void C()
{
    std::cout << "C started" << '\n';
    try{
        D();
    } catch (double){
        std::cerr << "C is handling the exception double" << '\n';
    }
    std::cout << "C ended" << '\n';
    return;
}

void B()
{
    std::cout << "B started" << '\n';
    try{
        C();
    } catch (const char*){
        std::cerr << "B is handling the exception const char*" << '\n';
    }
    std::cout << "B ended" << '\n';
    return;
}

int main(){

    try{
        B();
    } catch (int y ){
        std::cerr << "main is handling the exception int" << '\n';
    } 

    std::cout << "Life sucks";
}