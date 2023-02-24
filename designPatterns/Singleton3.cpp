#include "../../cppHeaders.h"

class Singleton{
    private:
        Singleton() {std::cout << "Ctor\n";};       //CONSTRUCTOR
        Singleton(const Singleton&);               //COPY consTRUTOR
        const Singleton& operator=(const Singleton&);  //A singleton instance can't be assigned with the = operator.
	    ~Singleton() {std::cout << "Dtor\n";};
        static Singleton* instance;
    public:
        static Singleton *getInstance();
};


Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance(){
    std::mutex mutex;
    std::scoped_lock lock(mutex);
    if(!instance){
        instance = new Singleton();
        std::cout << "first instance\n";
    } else{
        std::cout << "instance already existing\n";
    }
    return instance;
}

int main(){
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
}