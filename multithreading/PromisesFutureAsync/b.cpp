#include "includes.h"
//I return the value computed by reference. a condition variable is needed because 
std::mutex m;
std::condition_variable c;

int factorial(int n, int& x){
    int res = 1;

    for(int i = n; i>1; i--){
        res *= i;
    }
    x=res;
    c.notify_one();
}

int main(){
    int x;
    std::thread t1(factorial, 4, std::ref(x));
    c.wait(t1,x);
    std::cout << "Result is " << x;
    t1.join();
}