#include "cppHeaders.h"
#include "CHeaders.h"

class Prova{
    int _x, _y;
    public:
        Prova() = delete;
        Prova(int x, int y) : _x(x) , _y(y) {
            std::cout << "Prova created" << std::endl;
        }
        int func(){
            std::cout << _x << " " << _y << std::endl;
        }
        virtual std::string getName(){
            return "Prova";
        }
};

class Provetta : public Prova{
    char _r;
    public:
        void func1(){
            std::cout << _r << std::endl;
        }
        Provetta() = delete;
        Provetta(char r) : _r(r) ,Prova(0,0) {std::cout << "Provetta created" << std::endl;}
        std::string getName()override{
            return  "Provetta" ;
        }
};

class Provettina : public Provetta{
    const char* _name;
    public:
        Provettina() = delete;
        Provettina(const char* name) : _name(name) , Provetta(' ') {std::cout << "Provettina created" << std::endl;}
        std::string getName()override{
            return "Provettina";
        }
};

void fun1(Prova p){
    p.func();
}

void fun2(Prova *p){
    std::cout << p->getName() << std::endl;
}

int main(){
    Prova *p1 = new Prova(3,4);
    Provetta *p2 = new Provetta('e');
    Provettina *p3 = new Provettina("ijocd");

    fun2(p1);
    fun2(p2);
    fun2(p3);
}