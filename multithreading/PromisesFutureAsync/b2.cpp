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
    std::future<int> f = std::async(factorial, 4);  //create another thread
    x = f.get(); //the future is used to pass a value from the child to the parent
    return 0;
}