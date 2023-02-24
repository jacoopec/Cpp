#include "Quotation.h"

using namespace std;

	Quotation::Quotation(string productId_, double bidPrice_, double askPrice_, long timestamp_) 
		: productId(productId_), bidPrice(bidPrice_), askPrice(askPrice_), spread(askPrice - bidPrice), timestamp(timestamp_){
	}
	
	Quotation::Quotation(): bidPrice(0.0), askPrice(0.0), spread(0.0), timestamp(0){
	}

	string Quotation::getProductId() const{
		return productId;
	}

	double Quotation::getAskPrice() const {
		return askPrice;
	}

	double Quotation::getBidPrice() const {
		return bidPrice;
	}

	long Quotation::getTimestamp() {
		return timestamp;
	}

	double Quotation::getSpread() {
		return spread;
	}


