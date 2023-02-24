#include "includes.h"

template <typename T>
class Auto_ptr1{
        T* m_ptr;
        std::string _name;
    public:
        // Pass in a pointer to "own" via the constructor
        Auto_ptr1(T* ptr=nullptr)
            :m_ptr(ptr){
                // std::cout << "creating " << _name << " Resource\n";
            }

        // The destructor will make sure it gets deallocated
        ~Auto_ptr1(){
            // std::cout << "destroyign " << _name << " Resource\n";
            delete m_ptr;
        }

        // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
        T& operator*() const { return *m_ptr; }
        T* operator->() const { return m_ptr; }
};


// A sample class to prove the above works
class Resource{
    std::string _str;
    public:
        Resource(std::string str) : _str(str){ std::cout << "Resource " << str << " acquired\n"; }
        ~Resource() {
            std::cout << "Resource " << _str << " destroyed\n";
              }
};

void passByValue(Auto_ptr1<Resource> res){
    std::cout << "pass by value\n";
}


int main(){
	Auto_ptr1<Resource> res( new Resource("res1")); // Note the allocation of memory here
    // Auto_ptr1<Resource> res2(res);
    passByValue(res);
        // ... but no explicit delete needed

	// Also note that the Resource in angled braces doesn't need a * symbol, since that's supplied by the template
    std::cout << "Main\n";
	return 0;
} // res goes out of scope here, and destroys the allocated Resource for us