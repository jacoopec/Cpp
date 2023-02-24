#include "includes.h"

int n = 0;

void do_work(unsigned id){
    std::cout << "Started thread " << id << " do work \n"; n++;
    return;
}

int main(){
    std::vector<std::thread> threads; 
    std::cout << (int)std::thread::hardware_concurrency() << std::endl;
    std::cout << std::thread::id() << std::endl;
    for(unsigned i=0;i<20;++i){
        threads.push_back(std::thread(do_work,i));
    }

    std::cout << "Joining\n"; 
    std::for_each(threads.begin(),threads.end(),std::mem_fn(&std::thread::join));
}