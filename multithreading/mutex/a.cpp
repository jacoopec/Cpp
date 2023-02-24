#include "./2/includes.h"

std::mutex m;

struct Object{
    int a;
    int b;
};
std::vector<Object> v;

void function(Object o) {
    Object data;
    try {
        m.lock(); // <- exception could be thrown here
        v.push_back(data); // <- exception could be thrown here
        m.unlock();
    }
    catch(std::exception &e) {
        m.unlock(); // It is not safe to call if not locked!
        throw e;
    }
}