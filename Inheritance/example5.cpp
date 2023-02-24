#include "headers.h"


class Printable{
    public:
        virtual std::string getClassName() = 0;
};

class Sign : public Printable{
    const char* _location;
    const char* _kindOfSign;
    public:
        Sign(){}
        Sign(const char* location, const char* kindOfSign) :  _location(location), _kindOfSign(kindOfSign){ std::cout << "Created a Sign." << std::endl;}
        std::string getClassName() override {std::cout << "Sign" << std::endl;}
};

class Support{
    const char* _SupportType;
    public:
        Support(){}
        Support(const char* support) :  _SupportType(support){ std::cout << "Created a Support." << std::endl;}

};

class Maintainer{
    const char* _name;
    public:
    static int _maintainersNumber;
        Maintainer(const char* name) : _name(name){}
        Maintainer(){}

};

class RoadSign : public Sign , private Support{
    const char* _RoadType;
    Maintainer first;
    public:
        RoadSign(const char* type) 
            : _RoadType(type){std::cout << "Created a RoadSign." << std::endl;}

        // void display(){
        //     std::string s = 
        //     std::cout << s << std::endl;
        // }
};

void Print(Printable p)

int main(){
    RoadSign Stop("Stop");
}