class Base{
    int x, y, w;
    public:
        void setX(int x_){ x = x_;};
        void setY(int y_){ y = y_;};
        void setW(int w_){ w = w_;};
        Base(int x_, int y_, int w_) : x(x_), y(y_), w(w_) { std::cout << "Base created "<< std::endl;}
        void getVals(){
            std::cout << this->x << ", " << this->y << ", " << this->w << std::endl;
        }
        Base(){}
        virtual void getAttributes(){std::cout << x << ", " << y << ", " << w << std::endl;}
};