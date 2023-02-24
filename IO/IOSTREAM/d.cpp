#include "includes.h"

//STRING STREAMS 
int main()
{
    std::stringstream os;
    os << "3894 48 20";

    std::string strVal, strVal2;
    os >> strVal >> strVal2;
    // std::cout << os; no

    std::cout << strVal << "-" << strVal2;

}