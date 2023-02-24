#include "../cppHeaders.h"

class Resource{
    public:
        Resource() { std::cout << "Resource acquired\n"; }
        ~Resource() { std::cout << "Resource destroyed\n"; }
};


template <typename T>
class autoPtr{
    T* m_ptr;
    public:
        autoPtr(T* ptr = nullptr) : m_ptr(ptr){}
        ~autoPtr(){ delete m_ptr;}
        T& operator*() const { return *m_ptr; }
	    T* operator->() const { return m_ptr; }
};


void someFunction(Resource* r){
    Resource* ptr = new Resource(); // Resource is a struct or class
    std::cout << ptr << std::endl;
    r = ptr;
    // do stuff with ptr here

    delete ptr;
}

int main(){
    Resource* r;
    someFunction(r);
    std::cout << r;
}