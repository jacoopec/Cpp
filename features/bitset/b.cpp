#include "../../cppHeaders.h"


//coijewojoeeiowj



constexpr std::uint8_t mask0{0b0000'0001};
constexpr std::uint8_t mask1{0b0000'0010};
constexpr std::uint8_t mask2{0b0000'0100};
constexpr std::uint8_t mask3{0b0000'1000};
constexpr std::uint8_t mask4{0b0001'0000};
constexpr std::uint8_t mask5{0b0010'0000};
constexpr std::uint8_t mask6{0b0100'0000};
constexpr std::uint8_t mask7{0b1000'0000};

//comment

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
    std::cout << "Testing bit positions"<< std::endl;
    std::uint8_t flags{ 0b0000'0101 };
    std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags &= ~mask2; // turn off bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags &= ~(mask4 | mask5); // turn bits 4 and 5 off at the same time
}