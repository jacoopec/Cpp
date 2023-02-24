#include "includes.h"

int main(){
    int x{ 4 };
	std::cout << typeid(&x).name() << '\n';
}
