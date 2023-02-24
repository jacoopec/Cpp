#include "../../cppHeaders.h"

class ICommand{
    public:
        virtual void execute();
        virtual void unexecute();
};

class Invoker{
    ICommand *_on;
    ICommand *_off;
    // ICommand *_up;
    // ICommand *_down;
    public:
        Invoker(ICommand *on, ICommand *off/* , ICommand *up, ICommand *down */){
            this->_on = on;
            this->_off = off;
            // this->_up = up;
            // this->_down = down;
        }
        void clickOn(){
            this->_on->execute();
        }
        void clickOff(){
            this->_on->unexecute();
        }
};

class Light{
    public:
        void on(){}
        void off(){}
        Light(){}
}; 

class TurnOnLights : private ICommand{
    Light *_r;
    public:
        TurnOnLights(Light *r){this->_r = r;}
        void execute()override{
            _r->on();
        }
        void unexecute()override{
            _r->off();
        }
};

class TurnOffLights : private ICommand{
    Light *_r;
    public:
        TurnOffLights(Light *r){this->_r = r;}
        void execute()override{
            _r->off();
        }
        void unexecute()override{
            _r->on();
        }
};



int main(){
    Light uno;
    TurnOffLights second =TurnOffLights(&uno);
    TurnOnLights first   =TurnOnLights(&uno);
    Invoker Remote = Invoker(first,second);

}