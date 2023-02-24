#include "../../cppHeaders.h"

//SINGLETON
class Singleton{
    private:
        Singleton(){
        }
        static Singleton *instance;
    public:
        static Singleton *getInstance(){
            if(instance == nullptr){
                std::cout << "Creating Singleton" << std::endl;
                instance = new Singleton();
            } else {std::cout << "Singleton already exists" << std::endl; }
            return instance;
        }
};



int main(){
    Singleton *uno = Singleton.getInstance() ;
}