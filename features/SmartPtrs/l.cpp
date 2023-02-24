#include "../cppHeaders.h"

void print(std::string val){
    std::cout << val << '\n';
}

void print2(const std::string& val){
    std::cout << val << '\n';
}

//pass by address by reference
void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program

    return s_programName;
}


//ptr defaulted to nullptr
void greet(std::string* name=nullptr)
{
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest") << '\n';
}

int main(){
    std::string str{"Hello"};
    print(str);
    print2(str);
}