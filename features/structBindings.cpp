#include "cppheaders.h"
// binding let us deal with multiple return value better

std::tuple<std::string, int, char> CreatePerson(){
    return {"bsov", 23, 'f'}; //We are returning 2 types of data!
} 


int main(){
    std::tuple<std::string, int, char> person = CreatePerson();
    std::string& name  = std::get<0>(person);
    std::cout << std::get<0>(person) << "  " << std::get<1>(person)<< "  " << std::get<2>(person) << std::endl;
    
    std::string name2 = "joji";
    int age2 = 4;
    char f = 'f';
    std::tie(name2, age2, f) = CreatePerson();
    std::cout << "--------------------\n";
    // auto[name, age2, f] = CreatePerson();
    std::variant<std::string, int> data;
    data = "joicid";
    data = 2;
    std::cout << std::get<int>(data) << std::endl;
    std::cout << "--------------------\n";
    std::any data;
    data = 2;
    data = std::string("jiojc");
    std::any_cast<std::string>(data);

}
