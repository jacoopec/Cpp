#include "../cppHeaders.h"

class Shape{

    public:
        virtual double area() = 0;
};

//the virtual keyword provides the dynamic binding of the area fucntion at run time.
class Triangle : public Shape{
    double _base;
    double _height;
    public:
        Triangle(double base, double height) 
            : _base(base) , _height(height){}
        double area(){ return 0.5*_base*_height;}
};

class Square : public Shape{
    double _edge;
    public:
        Square(double edge){_edge = edge;}
        double area(){ return _edge * _edge;}
};

int main(){
    Shape *shapes[] = {
        new Square(3), new Triangle(3.2,5.4), new Square(5.4)
    };

    for(int i = 0; i < 3; i++){
        std::cout << shapes[i]->area() << std::endl;
    }
}