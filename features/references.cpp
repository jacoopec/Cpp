
namespace refs{
    enum cls : int{
        first = 0, second = 0, third = 0
    };

    int example1(int val);
    int example2(int& val);
    int example3(int* val);
    int& example4(int& val);

    class RefExp{
        int t;
        public:
            cls counter; 
            static cls globalCounter; 
            static int instancesCounter;
            int getT(){return t;}
            void setT(int t_){ t = t_;};
            static void getName(){
                std::cout << "RefExp";
            }
            RefExp(){
            }
            ~RefExp(){
            }
    };

    class washing{
        public:
            virtual void wash()= 0;
    };

    class GrandPa : public washing{
        private:
            int gpri_a;
        protected:
            int gpro_b;
        public:
            int gpu_x,gpu_y;
            virtual void getName(){ std::cout << "GrandPa" << std::endl;}
            void wash() override { std::cout <<"washGP";}

    };

    class DadPublic : public GrandPa{
        public:
            int dpu_w;
            virtual void getName() override { std::cout << "DadPublic" << std::endl;}
            void wash() override { std::cout <<"washDP";}
    };

    class DadPrivate : private GrandPa{
        public:
            int dpu_w2;
            virtual void getName() override { std::cout << "DadPrivate" << std::endl;}
            void wash() override { std::cout <<"washDP";}
    };

    class DadProtected : protected GrandPa{
        public:
            void wash() override { std::cout <<"wash";}
            int dpu_w3;
            virtual void getName() override { std::cout << "DadProtected" << std::endl;}
    };

    class Son : public DadPublic{
        public:
            void wash() override { std::cout <<"wash";}
            int spu_a;
            void getName() override { std::cout << "Son" << std::endl;}
    };


    RefExp& example5();
};



static int y;
int j;

int refs::example1(int val){
    std::cout <<"Address by reference1 " << &val << std::endl;
    return val;
}

int refs::example2(int& val){
    std::cout <<"Address by reference2 " << &val << std::endl;
    return val;
}

int refs::example3(int* val){
    std::cout <<"Address by reference3 " << val << std::endl;
    return *val;
}

int& refs::example4(int& val){
    std::cout <<"Address by reference4 " << &val << std::endl;
    return val;
}

refs::RefExp& refs::example5(){
    refs::RefExp t2;
    return t2;
}

void constExp::printEntity(const Entity& e){
    std::cout << e.getX()  << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const vecs::v& vec){
    stream << vec.a << " " << vec.b << " "  << vec.c << std::endl;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const vecs::String& string){

}


int main(){
            int a = 5;
        int& b = a;
        int y = 4;
        refs::RefExp t1;
        t1.counter = refs::cls::first;
        refs::RefExp::getName();
        std::cout << "&y: " << &y << std::endl;
        a = refs::example1(y);
        b = refs::example2(y);
        t1.setT(3);
        int c = refs::example3(&y);
        int& d = refs::example4(y);
        std::cout << "Returning reference: " << &d << std::endl;
        refs::RefExp& r = refs::example5();
        std::cout << "Returning reference: " << &r << std::endl;
}