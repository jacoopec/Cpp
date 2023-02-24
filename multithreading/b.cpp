#include "../cppHeaders.h"

class Baracca{
    public:
        void operator()(int x){
            while(x-->0){std::cout << x << std::endl;}
        }
        static void run(int x--){
            while(x-->0){std::cout << x << std::endl;}
        }
};

int main(){
    std::thread t([](int x){while(x >0){ std::cout << "x--" << x-- << " x " << x << " --x" << --x << std::endl;}}, 20);
    t.join();
    //-------------------------------
    std::thread t2(&Base::run,  20);
    t2.join();
    //-------------------------------
    Base b;
    std::thread t3(&Base::run, &b, 20);
    t3.join();
    system("pause>nul");
}