#include "../cppHeaders.h"
//assigning a function to a variable.
//in general a function is a symbol that we can call when we want something to happen
//function can also be passed as parameters and used to comput logic
//the functions are also compiled into CPU instructions and are somewhere in the binary
//we are retrieving the location of this function
//lambdas are used whenever there is a function pointer
// 

void Hello(int val){
    std::cout <<"Hello " << val << std::endl;
}

void forEach(const std::vector<int>& vals, void(*func)(int)){
    for(auto i = vals.begin(); i < vals.end(); i++){
        func(*i);
    }
}

std::string qualcosa(int g, std::string& s){

    return s;
}


void forEach3(const std::vector<int>& vals, void(*func)(int,int)){
    for(auto i = vals.begin(); i < vals.end(); i++){
        func(*i, *(i-1));
    }
}

int sum(int a, int b){
    return a + b;
}

int main(){
    Hello(8);  //this is a normal way of calling functions
//-------------------------------
    auto functionA = Hello;  //using auto
    auto functionB = &Hello;  //using auto
    functionA(4);
//-------------------------------
    void(*functionC)(int b) = Hello;
    functionB(3);
//-------------------------------
    typedef void(*HelloF)(int);
    HelloF func = Hello;
    func(3);
//-------------------------------
    auto f = Hello;
    // void* p2 = Hello;
    f(3);
    std::cerr << "eeror";
//-------------------------------
std::vector<int> v = {1,2,3,4,5,6,7};
    forEach(v,func);
    forEach(v,[](int a){std::cout << a;}); //here we are using a 
//-------------------------------
    int(*Sum)(int a, int b) = sum;
    forEach3(v, [](int a, int b){ std::cout << a+b << std::endl;});
//-------------------------------
    std::string(*qualcosina)(int y, std::string& s) = qualcosa;
//-------------------------------


//-------------------------------

}