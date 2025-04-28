#include "includes.h"

std::atomic<bool> readyFlag(false);

void thread1(){
    readyFlag.store(true);
}

void thread2(){
    while (!readyFlag.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main(){
    std::atomic_init(&readyFlag,false);
    std::cout << readyFlag.load();
    readyFlag.store(true);
    std::cout << readyFlag.load();
}