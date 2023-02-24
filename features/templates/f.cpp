#include "includes.h"

template <typename T> // this is the template parameter declaration
    T max(T x, T y) // this is the function template definition for max<T>
    {
        return (x > y) ? x : y;
    }

int main(){
    int res = max(32,53);
    max<int>(23,523);
}