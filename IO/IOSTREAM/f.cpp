#include "includes.h"

//STRING STREAMS 
int main(){
    std::ifstream inf{"text.txt"};
    if(!inf){
        std::cerr << "can't open";
        return 0;
    }
    while(inf){
        std::string strInput;
        inf >> strInput;
        std::cout << strInput + '\n';
    }
    return 0;
}