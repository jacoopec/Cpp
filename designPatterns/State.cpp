

class GateState{
    virtual void enterGS()=0;
    virtual void payGS()=0;
    virtual void payOkGS()=0;
    virtual void payFailedGS()=0;
};

class ClosedGate : public GateState{
    Gate *g;
};

class OpenGate : public GateState{
    Gate *_g;
    public:
        OpenGate(Gate g){
            this->_g = g; 
        }
        void payOk(){
            //let user in
            this->g.changeState(new ClosedGate(this._g));
        }

};


class Gate{
    GateState *gS = nullptr;

    public:
        Gate(GateState *initial){
            this->gS = initial;
        }
        void pay(){
            this->gS->payGS();
        }
        void payOk(){
            this->gS->payOkGS();
        }
        void payFailed(){
            this->gS->payFailedGS();
        }
        void changeState(GateState *s){
            this->gS = s;
        }
        void enter(){
            this->gS->enterGS();
        }
};

int main(){

}