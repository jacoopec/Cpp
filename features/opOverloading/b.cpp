#include "includes.h"
//overloading operators with normal functions

class Point{
    int _x, _y;
    public:
        Point(int x, int y): _x(x), _y(y) {}
        Point(): _x(0), _y(0) {}
        friend Point operator +(const Point p1, const Point& p2);
        Point operator !();

        int getPoint() const {return _x+_y;}
        const int getX(){ return _x;}
        const int getY(){ return _y;}
        void setX(int x){  _x = x;}
        void setY(int y){  _y = y;}
};

Point operator+(Point& p1, Point& p2){
    Point p(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    return p;
}
std::ostream& operator<<(std::ostream& op, Point& p){
    op << "Point(" << p.getX() <<"," <<  p.getY() << ")";
    return op;
}

std::istream& operator>> (std::istream& in, Point& point)
{
    // Since operator>> is a friend of the Point class, we can access Point's members directly.
    // note that parameter point must be non-const so we can modify the class members with the input values
    int x;
    int y;
    in >> x;
    point.setX(x);
    in >> y;
    point.setY(y);

    return in;
}

Point Point::operator!(){
    Point mp(-this->getX(), +this->getY());
    return mp;
}
//comment
//comment2

//comment5

int main(){
    Point po1();
    std::cin >> po1;
    Point po2();
    std::cin >> po2;
    Point po = po1 + po2;
    std::cout << po;
}