#include "includes.h"


void thrdFn(std::mutex& mtx, std::condition_variable& condVar){
    std::unique_lock<std::mutex> lock(mtx);
    condVar.wait(lock); //it replaces the while loop that waits for a condition to be verified.
}

int main(){
    std::mutex mt;
    std::condition_variable conVar;
    std::thread t{thrdFn, std::ref(mt), ref(conVar)};
    std::this_thread::sleep_for(std::chrono::seconds(2));
    conVar.notify_all();
    t.join();
} 