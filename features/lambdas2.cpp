#include "../cppHeaders.h"
//std::function constructs an empty function object.


int something2(){
    return 1;
}

void something(std::vector<int>& vals, void(*func)(int,int)){
    for(int i = 0; i< vals.size()-1; i++){
        func(i, i+1);
    }
}

int main(){
    std::vector<int> v = {1,2,3,4,5,6};
    auto lambda1 = [](int val, int sum){return val + sum; };
    auto lambda2 = [&](int val){std::cout << "val" << val << std::endl;};
    auto lambda3 = [](int val){std::cout << "val" << val << std::endl;};
    // something(v, lambda1);
    std::function<int()> fn1 = something2;
    
}