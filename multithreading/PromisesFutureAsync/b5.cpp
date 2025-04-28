#include "includes.h"


int findNumber(std::promise<long int>&& pr, std::vector<int> v){
    int res = 1;

    for(int i = v.size(); i>1; i--){
        if(v[i] == 3){
            pr.set_value(i);
        }
    }
}

int main(){
    int x;
    std::vector<int> v = {0,1,2,4,5,6,7,22,3};
    std::promise<int> p;
    std::future<int> fu = p.get_future();
    std::thread t(findNumber, std::move(p), v);  

    std::this_thread::sleep_for(std::chrono::milliseconds(29));
    p.set_value(3);
    //now the thread can work.
    x = f.get();//factorial function executed in the same thread
    return 0;
}