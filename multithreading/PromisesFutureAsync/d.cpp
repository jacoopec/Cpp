#include "includes.h"



int factorial(std::future<int>& f){
    int res = 1;
    int n = f.get();

    for(int i = n; i>1; i--){
        res *= i;
    }
    std::cout << "Result is ";
    return res;
}

int main(){
    int x;
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f) );
    p.set_value(4);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    x = fu.get();
    std::cout << x; //this will wait until the child thread finish and then return the result
}