#include "cppHeaders.h"
#include "CHeaders.h"

class String{
    private:
    char* m_Buf;
    unsigned int m_Size;
    public:
        String(const char* string){
            m_Size = strlen(string);
            m_Buf = new char[m_Size +1];
            memcpy(m_Buf, string, m_Size+1);
            m_Buf[m_Size] = 0;
        }
        String(const String& other) : m_Size(other.m_Size){
            std::cout << "Copied string" << std::endl;
            memcpy(m_Buf, other.m_Buf, m_Size+1);
            m_Buf = new char[m_Size+1];
        }
        ~String(){
            delete[] m_Buf;
        }
        char& operator[](unsigned int index){ return m_Buf[index];}
        friend std::ostream& operator <<(std::ostream&, const String& string);
};

std::ostream& operator <<(std::ostream& stream, const String& string){
    stream << string.m_Buf;
    return stream;
}

void Print(String string){
    std::cout << string << std::endl;
}

int main(){
    String string = "jciojdo";
    String second = string;
    Print(string);
}