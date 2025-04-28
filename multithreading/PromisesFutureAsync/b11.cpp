#include "includes.h"

void task1(){
    // endless insertion and memory allocation
    // - will sooner or later raise an exception
    // - BEWARE: this is bad practice
    std::list<int> v;
    while (true) {
        for (int i=0; i<100; ++i) {
            v.push_back(i); 
        }
        std::cout.put('.').flush();
    }
}

int main(){
    std::cout << "starting 2 tasks" << std::endl;
    std::cout << "- task1: process endless loop of memory consumption" << std::endl;
    std::cout << "- task2: wait for <return> and then for task1" << std::endl;
    std::future<void> f1 = std::async(task1); // start task1() asynchronously (now or later or never)
    std::cin.get(); // read a character (like getchar())
    std::cout << "\nwait for the end of task1: " << std::endl;
    try {
        // f1.wait(); // wait for task1() to finish (raises exception if any)
        f1.wait_for(std::chrono::seconds(2)); // wait for task1() to finish (raises exception if any)
        // f1.wait_until(std::system_clock::now()+std::chrono::seconds(1)); // wait for task() to finish (raises exception if any)
    }
    catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() <<  std::endl;
    }
}
