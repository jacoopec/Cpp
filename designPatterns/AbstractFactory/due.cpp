#include "../../cppHeaders.h"


class Wurstel
{
    public:
        virtual void name() = 0;
};
 
class BratWurst : public Wurstel 
{
    public:
        void name (){
            std::cout << " Brat wurstel \n";
        }
};
 
class WhiteWurst : public Wurstel 
{
    public:
        void name (){
            std::cout << " A white wurstel \n";
        }
};

class Prosciutto 
{
    public:
        virtual void name() = 0;
};
 
class ProsciuttoCotto : public Prosciutto 
{
    public:
        void name (){
            std::cout << " ProsciuttoCotto \n";
        }
};
 
class ProsciuttoCrudo : public Prosciutto {
    public:
        void name (){
            std::cout << " ProsciuttoCrudo \n";
        }
};


class MeatFactory 
{
    public:
        virtual Wurstel* createWurstel () = 0;
        virtual Prosciutto* createProsciutto () = 0;
};
 
class MeatFact1 : public MeatFactory 
{
    public:
        Wurstel* createWurstel (){
            return new BratWurst;
        }
        Prosciutto* createProsciutto (){
            return new ProsciuttoCotto;
        }
};
 
class MeatFact2 : public MeatFactory 
{
    public:
        Wurstel* createWurstel (){
            return new WhiteWurst;
        }
        Prosciutto* createProsciutto (){
            return new ProsciuttoCrudo;
        }
};
 
int main()
{
	MeatFactory* Rovagnati;
	Wurstel *wu;
	Prosciutto *pro;

	Rovagnati = new MeatFact1;
	wu = Rovagnati->createWurstel();
	wu -> name();
	pro = Rovagnati->createProsciutto();
	pro -> name();

	Rovagnati = new MeatFact2;
	wu = Rovagnati->createWurstel();
	wu -> name();
	pro = Rovagnati->createProsciutto();
	pro -> name();

	return 0;
}