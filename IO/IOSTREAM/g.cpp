#include "includes.h"

//STRING STREAMS 
int main(){
    std::ifstream inf{"text.txt"};
    std::string str;
    if(!inf){
        std::cerr << "can't open";
        return 0;
    }
    inf.seekg(2, std::ios::cur);
    std::getline(inf, str);
    std::cout << str;
    inf.seekg(4, std::ios::beg);
    inf.seekg(-3, std::ios::end);
    inf.seekg(3);
    return 0;
}