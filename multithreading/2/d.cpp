#include "includes.h"


class background_task{
    public:
        void operator()() const{
                std::cout << "ijcoid";
            }
};

int main(){
    background_task f;
    std::thread my_thread(f);
    // std::thread my_thread([int a,int b]((return a + b;)));
}