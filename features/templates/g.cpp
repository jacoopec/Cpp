#include "includes.h"

template <typename T, typename U>
    T max(T x, U y) // this is the function template definition for max<T>
    {
        return (x > y) ? x : y;
    }

int main(){
    int res = max(32,53.5);
    max<int>(23,523);
}