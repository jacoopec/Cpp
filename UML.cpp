#include "cppHeaders.h"

class Point{
    double _x;
    double _y;
};

//The center has a composition relationship with Circle, there is a strong relationship
//between the container and the containee, when The circle gets destroyed, the center is also destroyed.

class Circle {
    private:
        double radius;
        Point center;
    public:
        void setRadius(double radius);
        void setCenter(Point center);
        double getArea();
        double getCircumfrence();
};

//The class Decorate depends on the Circle class 
class Decorate{
    public:
        void decorating(Circle one){
            return;
        }
};

//the class Balls has an aggregation relationship with CIrcle.
class Balls{
    Circle uno;
    Circle due;
    Circle tre;
};

//The Backet class has an association relationship with Circle
class Basket{
    Circle *one;
};

int main(){

}