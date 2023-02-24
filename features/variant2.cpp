#include "cppHeaders.h"

std::variant<std::string,int> bo(bool b){
    if(b){
        return " bababrbrbababrahhhh";
    }
    return 2;
}

int main(){
    //variant creates space for both the data type in its variable
    std::variant<std::string, int> data;
    //data può essere assegnata ad uno dei due tipi
    data = "iojoci";
    std::cout << std::get<std::string>(data) << "\n";
    data = 5;
    std::cout << std::get<int>(data) << "\n";
    // std::string s = (std::string)bo(1);
    // std::cout <<  s;
    auto* val = std::get_if<std::string>(&data);  //if it exists returns a pointer to the string
}