#include "includes.h"

//STRING STREAMS 
int main(){
    std::ofstream outf{"text.txt"};
    if(!outf){
        std::cerr << "can't open";
        return 0;
    }

    outf << "This is line 1\n";
    outf << "This is line 2\n";
}