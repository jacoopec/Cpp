#include "includes.h"

void asyncFunc(){
    std::cout << "async fun\n";
}

int main(){
    std::future<void> fn = std::async(std::launch::async, asyncFunc);
    std::cout << "normal thread\n";
    fn.get();
}