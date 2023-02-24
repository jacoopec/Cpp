#include "cppheaders.h"

//returning an R value just returning the value 10, it doesn't have a locaiton.
int getValueR(){
    return 10;
}

//returning an L-value.
int& getValueL(){
    static int value = 10;
    return value;
} 

//this function can be called with an R or L value
void setValue(int val){

}

int main(){
    int i = 10;
    int a = i;
    std::cout << getValueL() << std::endl;
    getValueL() = 4;
    std::cout << getValueL() << std::endl;
    setValue(i);       //calling with an L value
    setValue(10);      //calling it with an R value. This R value will be used to create an L value when the function is called.
    //you can't take an L value reference from an R value
    //you can only have an L value reference of an L value

}