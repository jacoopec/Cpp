#include "includes.h"


int factorial(int n){
    int res = 1;

    for(int i = n; i>1; i--){
        res *= i;
    }
    return res;
}

int main(){
    int x;
    std::future<int> f = std::async(std::launch::deferred, factorial, 4);  //notcreate another thread
    //defer the execution until later it will be called.
    x = f.get();//factorial function executed in the same thread
    return 0;
}