#include "includes.h"

template <typename T>
void print (const T& arg){
    std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args){
    std::cout << firstArg << std::endl; // print first argument
    print(args...); // call print() for remaining arguments
}

int main(){
    
}