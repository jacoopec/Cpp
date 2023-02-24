void PrintVal(int val){
    std::cout << val;
}

void Printing(const std::vector<int>& vals, void(*fun)(int)){
    for(int val : vals)
        fun(val);
}

void f1(){
    return;
}

void f2(){
    return;
}

bool f3(bool g){
    return g;
}

std::string sf(){
    std::string s1 = "ui";
    return s1;
}



int main(){
                auto sfu = sf;
        typedef std::string(*sFunc)();
        sFunc sf1 = sf;
        std::cout << "Function pointers are just a way to assign a function to a variable. And function are CPU instruction." << std::endl;
        auto fun = &f1;
        fun = f1;
        fun();
        //
        void(*f)() = f1;  //assigning a function to a variable
        f();
        //
        auto functio = f3;
        bool gb = true;
        typedef bool(*functt)(bool);
        functt funcct = f3;
        bool o = funcct && funcct;
        std::cout << o;
        // bool(*funct)(gb) = f3;
        typedef void(*ff)();
        ff func = f1;
        std::vector<int> vals = { 1, 2, 3, 4, 5};
        Printing(vals, PrintVal);
        Printing(vals, [](int v){std::cout << v;});
}