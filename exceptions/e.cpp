#include "../../cppHeaders.h"

void fun(int *ptr, int c){
    if(ptr == nullptr) throw ptr;
    if(c == 0) throw c;
}

int main(){
    try{
        int g = 3;
        fun(&g, 3);
    } catch(...){
        std::cout << " Caught exception";
    }
}