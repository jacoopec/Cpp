#include "includes.h"

int main(){
    std::bitset<8> bits{ 0b0000'0101 };
    bits.set(2);
    bits.flip(4);
    bits.reset(1);
    std::cout << bits << std::endl;
    bits.flip(2);
    std::cout << bits << std::endl;
    std::cout << "Bit shifting"<< std::endl;
    std::cout << (bits >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (bits << 1) << '\n'; // shift left by 1, yielding 1000
    std::cout << "Bitwise"<< std::endl;
    std::cout << ~bits << std::endl;
    std::cout << "OR operator"<< std::endl;
    std::cout << std::bitset<4>{ 0b0101 } << " OR " << std::bitset<4>{ 0b0110 } << "   " << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';
    std::cout << std::bitset<4>{ 0b0101 } << " AND " << std::bitset<4>{ 0b0110 } << "   " << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';
    std::cout << std::bitset<4>{ 0b0101 } << " XOR " << std::bitset<4>{ 0b0110 } << "   " << (std::bitset<4>{ 0b0101 } ^ std::bitset<4>{ 0b0110 }) << '\n';
}