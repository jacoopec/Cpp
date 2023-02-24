#include "../../cppHeaders.h"

//ABSTRACT PANINO
class Panino{
    public:
        virtual std::string getDescription() = 0;
        virtual double cost() = 0;
};

//CONCRETE PANINO
class Hamburger : public Panino{
    public:
        std::string getDescription(){
            return "Pane->Carne";
        }
        double cost(){
            return 3.43;
        }
};

//CONCRETE PANINO
class PaninoSalame : public Panino{
    public:
        std::string getDescription(){
            return "Pane->Salame";
        }
        double cost(){
            return 5.3;
        }
};

//ABSTRACT DECORATOR
class PaninoDecorator : public Panino{
    protected:
        Panino *_decoratedPanino;
    public:
        PaninoDecorator (Panino *decoratedPanino) : _decoratedPanino(decoratedPanino){}
};

//CONCRETE DECORATOR
class SaladAdd : public PaninoDecorator{
    public:
        SaladAdd (Panino *_decoratedPanino): 
            PaninoDecorator(_decoratedPanino) {}
    
        std::string getDescription(){
            return _decoratedPanino->getDescription() +"->Salad";
        }
        double cost(){
            return 0.52;
        }
};

class SouceAdd : public PaninoDecorator{
    public:
        SouceAdd (Panino *_decoratedPanino): 
            PaninoDecorator(_decoratedPanino) {}
    
        std::string getDescription(){
            return _decoratedPanino->getDescription() +"->Souce";
        }
        double cost(){
            return 0.34;
        }

};



int main(){
    Panino *Bueno = new Hamburger();
    std::cout << "hamburger normale" << Bueno -> getDescription() << std::endl;

    Panino *paninoSalameInsalata = new SaladAdd ( new PaninoSalame());
    std::cout << "panino con salame e insalata" << paninoSalameInsalata -> getDescription() << std::endl;

    Panino *paninoSalameInsalataSalsa = new SouceAdd (paninoSalameInsalata);
    std::cout << "Panino con salame insalata e slasa" << paninoSalameInsalataSalsa -> getDescription() << std::endl;

    Panino *hamburgerWIthSauce = new SouceAdd (Bueno);
    std::cout << "hamburger con salsa" << hamburgerWIthSauce -> getDescription() << std::endl;
}