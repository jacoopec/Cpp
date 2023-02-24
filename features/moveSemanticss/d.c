#include "../cppHeaders.h"
#include "../CHeaders.h"

//Move semantics is used to avoid copying, moving the object allows to have higher performances

class String{
    char* m_Data;
    uint32_t m_Size;
    public:
        String() = default;
        String(const char* string){
            printf("Created\n");
            m_Size = strlen(string);
            m_Data = new char[m_Size];
            memcpy(m_Data, string, m_Size);
        }
        String(const String& other){  //COPY CONSTRUCTOR
            printf("Created\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);

        }
        String(const String&& other) noexcept{  //MOVE CONSTRUCTOR
            printf("Moved\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            other.m_Size = 0;
            other.m_Data = nullptr;

        }
        ~String(){
            printf("Destroyed\n");
            delete m_Data;
        }
        void Print(){
            for(uint32_t i = 0; i <  m_Size; i++){
                printf("%c", m_Data[i]);
            }
        }
    private:
        char* m_Data;
        uint32_t m_Size;
};

class Entity{
    String m_Name;
    public:
        Entity(const String& name) : m_Name(name){}
        Entity(const String&& name) : m_Name((String&&)name){} //questo costruttore prende un temporary come argomento
        void PrintName(){
            m_Name.Print();
        }
};

int main(){
    Entity entity(String("cijo"));
    entity.PrintName();
}