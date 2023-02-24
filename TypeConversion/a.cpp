#include "includes.h"

void allChar(){
    char c = -1;
    for(int i = 0; i < 260; i++, c++){
        std::cout << i << " " << (int)c << " "<< c << "\n";
    }
}

int main(){
    double d = 234343.43423;
    int i = static_cast<int>(d);
    char c = i;
    std::cout << d << " " << i;
    std::cout <<"Char overflow\n";
    std::cout << c << "\n";
    allChar();

}