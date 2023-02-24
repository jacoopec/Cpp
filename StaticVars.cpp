#include "../../cppHeaders.h"
#include "../../CHeaders.h"

class Prova{
    static int x, y;
};

int Prova::x;
int Prova::y;

int main(){
    char *buf = new char[8];
    int y = 0;
    void *vPtr = &y;
    std::cout << vPtr << std::endl;
    memset(buf, 'r', 8);
    std::cout << *buf << std::endl;
    delete[] buf;
    std::cout << *buf << std::endl;
}