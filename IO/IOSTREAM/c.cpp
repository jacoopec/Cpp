#include "includes.h"

int main()
{
    char strBuf[11];
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    //turning on flags
    std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';
    std::cout << std::hex << 23 << '\n';
    std::cout << std::dec << 23 << '\n';
    std::cout << std::oct << 23 << '\n';
    std::cout.unsetf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    //turning on ios flags 
    std::cout.setf(std::ios::showpos | std::ios::uppercase);
    std::cout << 3222121.43f;
    //turning off flags
    std::cout.unsetf(std::ios::showpos | std::ios::uppercase);

    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    return 0;
}