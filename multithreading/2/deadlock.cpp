#include "includes.h"
std::mutex m1;
std::mutex m2;

void fun2();

void fun1(){
    std::cout << "m1 locked by " << std::thread::get_id  <<"\n";
    m1.lock();
    fun2();
    m1.unlock();
    std::cout << "m1 unlocked by " << std::thread::get_id<< "\n";
}

void fun2(){
    std::cout << "m2 locked by " << std::thread::get_id  <<"\n";
    m2.lock();
    fun1();
    m2.unlock();
    std::cout << "m2 unlocked by " << std::thread::get_id << "\n";
}


void functionA(){
    std::cout << "I'm function A " << std::thread::get_id << "\n";
    fun1();
    fun2();
}

void functionB(){
    std::cout << "I'm function B " <<  std::thread::get_id << "\n";
    fun2();
    fun1();
}

int main(){
    std::thread t1(functionA);
    std::thread t2(functionB);
}