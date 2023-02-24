#include "../IOSTREAM/includes.h"
#include <vector>


int print(int a,int b){
    return a + b ;
}

int main(){
    int (*pFcn)(int,int){print};
    std::cout << pFcn(4,3);

}   