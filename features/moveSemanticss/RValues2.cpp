#include "cppheaders.h"

//this function works with l values
void printName(std::string& name ){
    std::cout << name << std::endl;
}

void printName(const std::string& name ){
    std::cout << name << std::endl;
}

int main(){
    //everything on the left is a left value, everything on the right is an R value
    std::string first = "bao";
    std::string last = "bab";
    std::string name = first + last;
    printName(first);
    printName(first + last);

}