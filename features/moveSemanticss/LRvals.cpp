#include "../../cppHeaders.h"

void fun(const int &lref){
    std::cout <<"lvalue ref to const";
}

void fun(int &&rref){
    std::cout <<"rvalue ref";
}

int main(){
    int c = 5;
    fun(c);
    fun(3);
}