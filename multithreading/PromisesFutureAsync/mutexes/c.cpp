#include "includes.h"
//making sure that t will join with or without exception

void thrdFn(std::mutex& mtx, std::condition_variable& condVar){
    std::cout << "ddddddddddd\n";
}

int main(){
    std::thread t{thrdFn};

    try{
        for(int i =0; i<100;i++) std::cout << "jjjjjj\n";
        t.join();
    } catch(...){
        t.join();
        throw;
    }
    t.join();
} 