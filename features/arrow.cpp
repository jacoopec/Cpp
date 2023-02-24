#include "cppHeaders.h"

class Entity{
    public:
        int x;
        void Print() const {std::cout << "cjoij" << std::endl;}
};

class ScopedPtr{
    Entity* m_obj;
    ScopedPtr(Entity* entity) : m_obj(entity){}
    ~ScopedPtr(){ delete m_obj;}
    Entity* operator->(){return m_obj;}
};

int main(){

    ScopedPtr entity = new Entity();
    entity->Print();

}