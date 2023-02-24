#include "includes.h"
//Here I don't return the result from the thread to the main thread, I just print it from the thread
void factorial(int n){
    int res = 1;

    for(int i = n; i>1; i--){
        res *= i;
    }
    std::cout << "Result is " << res;
}

int main(){
    std::thread t1(factorial, 4);
    t1.join();
}