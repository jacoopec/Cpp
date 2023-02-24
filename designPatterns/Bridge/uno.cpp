#include "../../cppHeaders.h"
#include <cstdlib>

class IResource{
    virtual std::string snippet() = 0;
    virtual std::string title() = 0;
    virtual std::string image() = 0;
    virtual std::string url() = 0;
};

class View{
    protected:
        IResource *IR;
    public:
        View(IResource *r){
            this->IR = r;
        }
        virtual std::string Show()=0;
};

class LongForm : public View{
    public:
        std::string Show() override{
            this->IR 
        } 
};

class Artist{
    public:
        std::string name;
};

class ArtistResource : public IResource{
    Artist *_a;
    public:
        ArtistResource(Artist *a){
            this->_a = a;
        }
        std::string snippet()override{

        }
        std::string title(){

        }
        std::string image(){

        }
        std::string url(){
        }
};

int main(){

}