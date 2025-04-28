#include "../../cppHeaders.h"

int main(){
    try{
        int m = 32;
        int n = 233;
        if( n > m ){
            throw 20;
        }
    } catch(...){
        std::cout << "m can't be less than n.";
    }
}