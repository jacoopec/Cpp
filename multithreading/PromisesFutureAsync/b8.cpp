#include "includes.h"

void threadFun(std::mutex& mtx){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Mutex locked\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main(){
    std::mutex mtx;
    std::thread th{threadFun, ref(mtx)};
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Inside main thread\n";
    lock.lock();
    lock.unlock();
    th.join();
    return 0;
}