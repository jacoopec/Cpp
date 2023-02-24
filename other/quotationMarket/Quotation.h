#include <string>

using namespace std;



class Quotation
{
private:
		string productId;
		double bidPrice, askPrice, spread;
		long timestamp;
public: 
		Quotation(string productId, double bidPrice, double askPrice, long timestamp);
		Quotation();
		string getProductId() const;
		double getAskPrice() const;
		double getBidPrice() const;
		long getTimestamp();
		double getSpread();
};

bool operator==(Quotation const& l, Quotation const& r);
