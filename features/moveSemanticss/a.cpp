#include "cppheaders.h"
#include "headers.h"

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
        
        //Copy constructor
        String(const String& string){
            printf("copied\n");
            m_Size = string.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, string.m_Data, m_Size);
        }

        String(String&& other) noexcept{
            printf("Moved\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        ~String(){
            delete m_Data;
        }

        void Print(){
            for(uint32_t i = 0; i < m_Size)
        }
};

class Entity{
    String m_Name;
    public:
        Entity(const String& name) : m_Name(name){

        }

        Entity(String&& name) : m_Name(name){

        }
        void printName(){
            m_Name.Print();
        }
};

int main(){
    Entity e("hiooi");
}