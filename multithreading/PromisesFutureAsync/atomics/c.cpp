#include "includes.h"

long data;
std::atomic<bool> readyFlag(false);

class spinlock_mutex{
        std::atomic_flag flag;
    public:
        spinlock_mutex():
        flag(ATOMIC_FLAG_INIT){}
        void lock(){
            while(flag.test_and_set(std::memory_order_acquire));
        }
        void unlock(){
            flag.clear(std::memory_order_release);
        }
};

int main(){
    // start provider and consumer
    auto p = std::async(std::launch::async,provider);
    auto c = std::async(std::launch::async,consumer);
}