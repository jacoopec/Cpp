#include "includes.h"

template<typename Iterator,typename T>
struct accumulate_block{
    void operator()(Iterator first,Iterator last,T& result){
        result=std::accumulate(first,last,result);
    }
};

int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << sum;
}