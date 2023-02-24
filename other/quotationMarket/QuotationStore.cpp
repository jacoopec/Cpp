#include "QuotationStore.h"
#include <iostream>

void QuotationStore::storeQuotation(Quotation newQuote) {
	auto it = quotationsList.begin();
	it = quotationsList.insert(it,newQuote);
}

Quotation QuotationStore::getLastReceivedQuoteByProductId(string productId){
	//implement this function
	Quotation q;
	long biggestTimeStamp;
	const char * str = new char[str.size() + 1];
	std::copy(productId.begin(), productId.end(), str)
	try{
		throw QuotationNotFoundException(str);
		for(list<Quotation>::iterator it = quotationsList.begin(); 
			it != quotationsList.end(); it++){
				if(it->getProductId() == productId){
					if(biggestTimeStamp > it->getTimestamp())
						{q = *it;}
				}
			} 
		return q;
	} catch(QuotationNotFoundException& e){
		std::cout << e.what() << std::endl;
	}
}

list<Quotation> QuotationStore::getSpreadsListByInstrument(string productId, bool descending) {
	
	list<Quotation> quotationListToReturn;

	// std::sort(quotationsList.begin(),quotationsList.end(), [](long a, long b){ return a < b;});
	for(list<Quotation>::iterator it = quotationsList.begin(); 
		it != quotationsList.end(); it++){
		for(list<Quotation>::iterator it2 = quotationListToReturn.begin(); 
		it2 != quotationListToReturn.end(); it2++){
			if(!descending){
				if(it->getSpread() > it2->getSpread()){
					quotationListToReturn.insert(it2, *it);
				}
			} else {
				if(it->getSpread() < it2->getSpread()){
					quotationListToReturn.insert(it2-1, *it);
				}
			}
		}
	}

	return quotationListToReturn;
}


bool operator==(Quotation const& l, Quotation const& r) {
	 
	if (l.getAskPrice() != r.getAskPrice()) {
		return false;
	}
	
	if (l.getBidPrice() != r.getBidPrice()) {
		return false;
	}

	if (l.getProductId() != r.getProductId()) {
		return false;
	}

	return true;
}