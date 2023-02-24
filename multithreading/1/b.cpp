#include "includes.h"

std::mutex m;
int a = 0;


void thread_1() {
    for(int i = 0; i < 1000; ++i){
        // m.lock();
        a++; 
        // m.unlock();
    }
}

void thread_2() {
    for(int i = 0; i < 1000; ++i){
        // m.lock();
        a--; 
        // m.unlock();
    }
}

int main(){
    std::cout << a << "\n";
    thread_1();
    // std::cout << a << "\n";
    thread_2();
    std::cout << a << "\n";
}