#include "includes.h"



int factorial(int n){
    int res = 1;

    for(int i = n; i>1; i--){
        res *= i;
    }
    std::cout << "Result is " << res;
    return res;
}

int main(){
    int x;
    std::promise<int> p;
    std::future<int> f = std::async(std::launch::deferred | std::launch::async, factorial, 4 );
    x = f.get(); //this will wait until the child thread finish and then return the result
}