#include "includes.h"


int factorial(std::future<int>& f){
    int res = 1;

    int n = f.get();
    for(int i = n; i>1; i--){
        res *= i;
    }
    return res;
}

int main(){
    int x;
    std::promise<int> p;
    std::future<int> fu = p.get_future();
    std::future<int> f = std::async(std::launch::async, factorial, std::ref(fu));  
    //It is possible to pass values to the child thread at some point in the future
    //thread is created, but now I do something else.
    std::this_thread::sleep_for(std::chrono::milliseconds(29));
    p.set_value(3);
    //now the thread can work.
    x = f.get();//factorial function executed in the same thread
    return 0;
}