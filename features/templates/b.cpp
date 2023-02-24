#include "includes.h"

template <typename T,typename U> // this is the template parameter declaration
auto max(T x, U y){
    return (x > y) ? x : y;
}

int main(){
    int res = max(32,53);
    std::cout << max<int>(23,523) << "\n";
    std::cout << max<double>(23.32,52.3);
}