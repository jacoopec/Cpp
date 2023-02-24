#include "includes.h"

int main(){
    std::fstream iofile{ "Sample.txt", std::ios::in | std::ios::out };
    if(!iofile){
        std::cerr << "Error";
    }
    char ch;
    iofile.seekg(4, std::ios::cur);
    std::get(iofile, ch);
    std::cout << ch;
    iofile << '#';
    iofile.seekg(iofile.tellg(), std::ios::beg);
        
    
}