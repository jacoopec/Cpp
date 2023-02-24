#include "../../cppHeaders.h"
//input only alphabetic chars or spaces. If anything else is encountered it will be rejected.

int main(){
    std::ofstream outf;
    outf.open("file5.txt", std::ofstream::app);
    if(outf.fail()){
        std::cout << "Error opening the file." << std::endl;
        return;
    }
    outf << "Content "  << std::endl;
    outf.close();
}