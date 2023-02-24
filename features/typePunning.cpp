#include "cppheaders.h"

struct Entity{
    int x,y;
};

int main(){
    Entity e = {1,2};
    int* position = (int*)&e;
    int y = *(int*)((char*)&e+4);  //accessing y
    std::cout << position[0] << ", " << position[1] << ", " << y;

    union{
        float a;
        int b;
    };
}