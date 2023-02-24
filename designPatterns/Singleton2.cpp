#include "cppHeaders.h"
//singleton applies to a global set of datac
class Singleton{
    Singleton(){}
    static Singleton s_Instance;
    public:
        Singleton(const Singleton&) = delete; //delting the copy constructor
        static Singleton& get(){
            return s_Instance;
        }
        void Function(){}
};

Singleton Singleton::s_Instance;

int main(){
    Singleton::get().Function();
}