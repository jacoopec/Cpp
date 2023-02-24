#include "./2/includes.h"


std::condition_variable condvar;
std::mutex m;
bool signal = false;


/ thread …
 {
std::unique_lock<std::mutex> lock(m);
condvar.wait(lock, []() { return signal; });
signal = false;
// while the thread is waiting the mutex is unlocked!
std::cout << “this thread just woke up!” << endl;
 }


// thread …
{
std::lock_guard<std::mutex> lock(m);
signal = true;
}
condvar.notify_one(); 

int main(){

}
