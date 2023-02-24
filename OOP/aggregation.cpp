#include "includes.h"

class Teacher{
    private:
    std::string m_name{};

    public:
    Teacher(const std::string& name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

class Department{
    private:
    const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

    public:
    Department(const Teacher& teacher)
        : m_teacher{ teacher }{}
};

int main(){
    
    Teacher bob{ "Bob" }; 
    {
        Department department{ bob };
    } 
  
    std::cout << bob.getName() << " still exists!\n";
    return 0;
}