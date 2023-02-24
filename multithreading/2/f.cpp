#include "includes.h"

std::mutex m;

struct func{
    int& i;
    func(int& i_):i(i_){}
    void operator()(){
        for(unsigned j=0;j<1000;++j){
            std::cout << i;
        }
    }
};

class thread_guard{
    std::thread& t;
    public:
        explicit thread_guard(std::thread& t_): t(t_){
            std::cout << "Thread created";
        }
        ~thread_guard(){
            if(t.joinable()){
                t.join();
            }
            std::cout << "Thread destroyed";
        }
        thread_guard(thread_guard const&) = delete;
        thread_guard& operator = (thread_guard const&) = delete;

};

void printing(){
    std::cout << "\nThread " << std::thread::get_id << " locking\n";
    m.lock();
    for(unsigned j=0;j<1000;++j){
        std::cout << "i";
    }
    m.unlock();
    std::cout << "\nThread " << std::thread::get_id << " unlocking\n";
}

int main(){
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(printing);
    std::thread t2(printing);
    thread_guard g(t);
}