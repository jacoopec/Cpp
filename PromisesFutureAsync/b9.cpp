#include "includes.h"

int doSomething (char c){
    // random-number generator (use c as seed to get different sequences)
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10,1000);
    // loop to print character after a random period of time
    for (int i=0; i<10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
        std::cout.put(c).flush();
    }
    return c;
}

int func1 (){
    return doSomething('.');
}

int func2 (){
    return doSomething('+');
}

int main(){
    // std::future<int> result1(std::async(std::launch::deferred, func1));
    std::future<int> result1(std::async(std::launch::async, func1));
    int result2 = func2(); // call func2() synchronously (here and now)
    // print result (wait for func1() to finish and add its result to result2
    int result = result1.get() + result2;
    std::cout << "\nresult of func1()+func2(): " << result << std::endl;
}