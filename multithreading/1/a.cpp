#include "includes.h"

void hello(){
    std::cout << "Hello";
}

int main(){
    std::thread t(hello);
}