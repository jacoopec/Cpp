#include "includes.h"

int main(){
        // Define a bunch of physical/emotional states
	[[maybe_unused]] constexpr std::bitset<8> isHungry{	0b0000'0001 };
	[[maybe_unused]] constexpr std::bitset<8> isSad{	0b0000'0010 };
	[[maybe_unused]] constexpr std::bitset<8> isMad{	0b0000'0100 };
	[[maybe_unused]] constexpr std::bitset<8> isHappy{	0b0000'1000 };
	[[maybe_unused]] constexpr std::bitset<8> isLaughing{	0b0001'0000 };
	[[maybe_unused]] constexpr std::bitset<8> isAsleep{	0b0010'0000 };
	[[maybe_unused]] constexpr std::bitset<8> isDead{	0b0100'0000 };
	[[maybe_unused]] constexpr std::bitset<8> isCrying{	0b1000'0000 };


	std::bitset<8> me{}; // all flags/options turned off to start
	me |= (isHappy | isLaughing); // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states (we use the any() function to see if any bits remain set)
	std::cout << "I am happy? " << (me & isHappy).any() << '\n';
	std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';

	return 0;
}