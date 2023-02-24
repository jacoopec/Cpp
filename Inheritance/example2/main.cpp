

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



int main(){
            refs::GrandPa GP;
        refs::Son RJ;
        refs::DadPublic R1;
        refs::DadPrivate R2;
        refs::DadProtected R3;
        R1.dpu_w = 3;
        R1.gpu_x = 3;
        R1.gpu_y = 3;
        R1.getName();
        R2.dpu_w2 = 3;
        R2.getName();
        R3.dpu_w3 = 3;
        R3.getName();
        RJ.getName();
        GP.getName();
        std::cout << " R1 size: " << sizeof(R1) << " R2 size: " << sizeof(R2) << " R3 size: " << sizeof(R3) << " Son size: " << sizeof(RJ) << " GrandPa size: " << sizeof(GP)<< std::endl;

}