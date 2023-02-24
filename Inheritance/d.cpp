#include "includes.h"


class A{
    protected:
        std::string name;
        int numb;
    public:
        A(int a, std::string name, int numb){
            std::cout << "A: " << a << '\n';
        }
};

class B: public A
{
public:
    B(int a, double b, std::string name, int numb)
    : A{ a ,name, numb}
    {
        std::cout << "B: " << b <<  '\n';
    }
};

class C: private A
{
public:
    C(int a,  char c, std::string name, int numb)
    : A{ a,  name, numb }
    {
        std::cout << "C: " << c << '\n';
    }
    void getProtectedAtt(){
        std::cout << name << numb << "\n";
    }
};

class D: protected A
{
public:
    D(int a,  char c, std::string name, int numb)
    : A{ a,  name, numb }
    {
        std::cout << "C: " << c << '\n';
    }
    void getProtectedAtt(){
        std::cout << name << numb << "\n";
    }
};

int main()
{
    C c{ 5,  'R',"ijcod",32 };

    return 0;
}