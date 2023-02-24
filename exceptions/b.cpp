#include "../../cppHeaders.h"

void function(int uno)
{
    if(uno > 1){
        throw "too big";
    }
    return;
}

int main(){

    try{
        function(3);
    } catch (int y ){
        std::cerr << "int exception" << '\n';
    } catch (double y ){
        std::cerr << "double exception"<< '\n';
    } catch (const char *){
        std::cerr << "Too big exception"<< '\n';
    } catch (const std::string& s){
        std::cerr << "string exception"<< '\n';
    }

    std::cout << "Life sucks";
}