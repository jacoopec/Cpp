

class Base{
    public:
        Base(){std::cout << "Base Constructor\n";}
        ~Base(){std::cout << "Base Destructor\n";}
};

class Derived : public Base{
    public:
        Derived(){std::cout << "Derived constructor\n";}
        ~Derived(){std::cout << "Derived Destructor\n";}
};

int main(){
    Base* base = new Base();
    delete base; //creating it on the heap so that we can be explict with creation and deletion
    std::cout << "--------\n";
    Derived* derived = new Derived();
    delete derived;
    std::cout << "--------\n";
    Base* poly = new Derived();
    delete poly;

}