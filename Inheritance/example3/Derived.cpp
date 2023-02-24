class Derived : public Base , public Product{
    const char* name;
    public:
        Derived(const char* name_, int x_, int y_, int w_) : name(name_){std::cout << "Derived created "<< std::endl;}
        void getAttributes() override{std::cout << name << std::endl;}
        int AddProduct(int elems){}

};