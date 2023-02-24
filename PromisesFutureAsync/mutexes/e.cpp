#include "includes.h"


void thrdFn(std::string& s){
    std::cout << s << "\n";
    s = "jcodjo";
}

int main(){
    std::mutex mt;
    std::condition_variable conVar;
    std::string s = "jcodijs";
    std::thread t{thrdFn, std::ref(s)};
    std::cout << s;
    t.join();
} 