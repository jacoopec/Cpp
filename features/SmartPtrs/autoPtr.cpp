#include "../../cppHeaders.h"

template <typename T>
class auto_ptr1{
    T* m_ptr;
    public:
        auto_ptr1(T* ptr = nullptr) : m_ptr(ptr){}
    ~auto_ptr1(){delete m_ptr;}
    T& operator*() const {return *m_ptr;}
    T* operator->() const {return m_ptr;}
};

class WhatEver{
    public:
        WhatEver(){std::cout << "created\n";}
        ~WhatEver(){std::cout << "destructed\n";}
};

int main(){
    auto_ptr1<WhatEver> wh(new WhatEver());
    return 0;
}