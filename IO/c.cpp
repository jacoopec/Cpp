#include "../../cppHeaders.h"

int main(){
    unsigned int choice;
    char buffer[10];
    char ch;
    std::string str;
    std::cout << "Input choice: 0,1,2,3" << std::endl;
    std::cin >> choice;
    if(choice == 0){
        std::cin >> std::setw(10) >> buffer;
    } else if (choice == 1){
        while(std::cin.get(ch)) std::cout << ch;  //alternative version
    } else if(choice == 2) {
        std::cin.get(buffer, 10);        
        std::cout << buffer <<std::endl;  //another version
    } else if(choice == 3) {
        std::cin.getline(buffer, 10);        
        std::cout << buffer <<'\n';  //another version
    } else if(choice == 4) {
        std::getline(std::cin, str);        
        std::cout << "getline for std::string" << buffer <<'\n';  //another version
    }
}