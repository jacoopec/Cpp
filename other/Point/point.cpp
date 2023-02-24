#include <ostream>
#include <fstream>
#include <iostream>

class Point{
    int x, y;
    public:
        Point(int x_, int y_){ this->x = x_; this->y = y_;}
        Point(){};
        int getX() const { return x;}
        int getY() const { return y;}
        Point operator+(Point p){
            Point pn;
            pn.x = x + p.x;
            pn.y = y + p.y;
            return pn;
        }

        bool operator==(Point p){
            return(*this == p);
        }
};

std::ostream& operator<<(std::ostream& ostream, const Point& p){
    ostream << p.getX() << " , " << p.getY();
    return ostream;
}