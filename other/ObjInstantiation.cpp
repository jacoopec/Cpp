#include "cppHeaders.h"

class Obj{
    Obj(){std::cout << "Obj created" << std::endl;}
    ~Obj(){std::cout << "Obj destroyed" << std::endl;}
};

int main(){
    std::cout << "Main scope" << std::endl;
    Obj tre();
    {
        Obj due();
        std::cout << "First scope" << std::endl;
        {
            std::cout << "Second scope" << std::endl;
            Obj uno();

            std::cout << "Second scope ends" << std::endl;
        }
        std::cout << "First scope ends" << std::endl;
    }
    std::cout << "Main scope ends" << std::endl;
}