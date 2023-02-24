#include "includes.h"

void operation(std::stack<int>& s){
    if(!s.empty()){
        int const value = s.top();
        s.pop();
    }

}

int main(){
    std::stack<int> s;
    s.push(3);
    s.push(1);
    s.push(3);
    s.push(5);

    std::thread t1(operation);
    std::thread t2(operation);


}