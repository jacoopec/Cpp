#include "../../cppHeaders.h"
#include <cstdlib>


class ITarget{
    public:
        virtual void request() = 0;
};

class Client{
    ITarget * u;
};

class Adaptee{
    public:
        void specifRequest(){
            std::cout << "Specific request\n";
        }
};

class Adapter : public ITarget{
    Adaptee *_a;
    public:
        void request() override{
            _a->specifRequest();
        }
        Adapter(Adaptee *a){
            this->_a = a;
        }
};


int main(){
    ITarget *target = new Adapter(new Adaptee());
    target->request();
    IT
}