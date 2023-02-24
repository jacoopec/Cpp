#include "includes.h"


void thrdFn(std::string& s){
    std::cout << s << "\n";
    s = "jcodjo";
    std::cout << std::this_thread::get_id();
}


class Stack{
    int* _data;
    std::mutex _mu;
    public:
        int& pop();
        int& top();
};

void function_1(Stack& st){
    int v = st.pop();
}

int main(){
    std::mutex mt;
    std::condition_variable conVar;
    std::string s = "jcodijs";
    std::thread t{thrdFn, std::move(s)};
    std::cout << s;
    t.join();
} 