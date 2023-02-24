#include "../../cppHeaders.h"

class IPayment{
    virtual void pay() = 0;
};

class CashPayment : public IPayment{
    void pay(){std::cout << "Pay with cash" << std::endl;}
};

class CardPayment : public IPayment{
    void pay(){std::cout << "Pay with card" << std::endl;}
};