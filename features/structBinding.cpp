#include "cppHeaders.h"
//structure bindings are a feature that allows to deal with multiple return values better
//return tuples and pairs
//return instances struct that contain data (or classes)

struct Pero{
    int age;
    char* name;
    Pero(int a, char* p){
        this->age = a;
        this->name = p;
    }
};

std::tuple<std::string, int, char> createPerson(){
    return{"bababa", 32, 'r'};
}

Pero bo(int y, char* nametto){
    Pero p = Pero(y,nametto);
    return p;
}


int main(){
    //---------------------------------
    auto person = createPerson();
    //GEtting values from person
    std::cout << std::get<0>(person) << " " << std::get<1>(person) << " " << std::get<2>(person) << std::endl;
    //---------------------------------
    std::string name;
    int numb;
    char r;
    std::tie(name, numb, r) = createPerson();
    //---------------------------------STRUCTURE BINDINGS
    auto[charlie, brown, m] = createPerson();
    std::cout << charlie << " " << brown << " " << m << std::endl;
    //---------------------------------


}