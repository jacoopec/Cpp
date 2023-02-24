#include "./2/includes.h"

void worker(std::string name, int n){
    for (int i = 0; i < n; ++i) {
        std::cout << std::this_thread::get_id << ":" << n << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


int main(){
    std::thread t (worker,"hello world", 10);
    std::vector<std::thread> workers;
    workers.push_back(std::move(t));
    bool test = t.joinable(); // true
    t.join(); 
}