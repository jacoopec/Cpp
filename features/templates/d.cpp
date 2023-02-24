#include "includes.h"

template <typename T> // this is the template parameter declaration
    T max(T x, T y) // this is the function template definition for max<T>
    {
        return (x > y) ? x : y;
    }

class Cents{
    private:
        int m_cents {};

    public:
        Cents(int cents) : m_cents{ cents } { }
        friend Cents operator+(const Cents& c1, const Cents& c2);
        int getCents() const { return m_cents; }
};


Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + c2.m_cents;
}

int main(){
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";
}