#include "includes.h"

void some_function(){
    return;
}

void some_other_function(){
    return;
}

std::thread f(){
    return std::thread(some_function);
}

int main(){
    std::thread t1(some_function);
    std::thread t2 = std::move(t1);
    t1 = std::thread(some_other_function);
    std::thread t3;
    t3=std::move(t2);
    t1=std::move(t3);
}