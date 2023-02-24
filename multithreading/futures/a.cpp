#include "../2/includes.h"

int func(){
    return 2;
}

int main(){
    std::future<int> f(std::async(func));
    f.wait_for(std::chrono::seconds(10));
    // f.wait_until(std::system_clock::now()+std::chrono::minutes(1));
}