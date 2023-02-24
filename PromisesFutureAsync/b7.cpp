#include "includes.h"

void asyncFunc(std::promise<int>& prom){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prom.set_value(192);
    std::cout << "async fun\n";
}

int main(){
    std::promise<int> myP;
    std::future<int> fn = myP.get_future();
    std::thread t1{asyncFunc, ref(myP)};
    std::cout << "normal thread\n";
    fn.get();
    t1.join();
}