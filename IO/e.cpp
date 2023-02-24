#include "../../cppHeaders.h"

int main(){
    unsigned int choice;
    char buffer[10];
    char ch;
    std::string str;
    std::cout << "Input choice: 0,1,2,3" << std::endl;
    std::cin >> choice;
    int number;
    if(choice == 0){
    } else if (choice == 1){
        std::cout << "Enter a number" << std::endl;
        std::cin >> number;
        std::cout << "Hex" << std::hex << number << "dec" << std::dec << number << "oct" << std::oct << number << std::endl;
        std::cout << std::setprecision(3) << number << std::endl;
    } else if(choice == 2) {
        std::cout << "setw with fill" << std::endl;
        std::cout.fill('*');
        std::cout << -12345 << '\n'; // print default value with no field width
        std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
        std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
        std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
        std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    } else if(choice == 3) {
        std::cout << "setw" << std::endl;
        std::cout << -12345 << '\n'; // print default value with no field width
        std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
        std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
        std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
        std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    } else if(choice == 4) {
    }
}