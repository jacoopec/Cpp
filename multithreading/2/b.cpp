#include "includes.h"

//the problem here is that the new thread will probably still be running when oops exits,
//you have implicetely decided not to wait for it by calling detach().
//the next call to do_something(i) will access an already destroyed variable.
//allowing a ptr or ref toa  local variable to persists beyond tha function exit is never a good idea
struct func{
    int& i;
    func(int& i_):i(i_){}
    void operator()(){
        for(unsigned j=0;j<1000000;++j){
            std::cout << i;
        }
    }
};

void f(){
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try{
        for(unsigned j=0;j<1000000;++j){
            std::cout << 'i';
        }
    }
    catch(...){
        t.join(); 
        throw;
    }
    t.join();
}


int main(){
    oops();
    std::cout << "ending main";
}