#pragma once

#include <map>
#include <list>

#include "Quotation.h"

class QuotationNotFoundException : public exception {
	
	private:
		string errorMessage;
	public:
		QuotationNotFoundException(string productId){
			errorMessage = errorMessage.append(productId).append(" not found in store!");
		}
	 
		const char* what() const throw () {
			return errorMessage.c_str();
		}
};

class QuotationStore
{

private:

	std::list<Quotation> quotationsList;

public:
	/*
	 * Register a new Quotation in the store.
	 */
	void storeQuotation(Quotation newQuote);

	/*
	 * Return the quote with the greater timestamp ever received for the given instrument.
	 * If multiple quotes are stored with the same timestamp, the most recently received one
	 * is considered the last.
	 * Throws QuoteNotFoundException if no quote is found.
	 */
	Quotation getLastReceivedQuoteByProductId(string productId);

	/*
	 * Return a list of quotations for the given instrument, sorted by decreasing or ascending order of the spread.
	 */
	list<Quotation> getSpreadsListByInstrument(string productId, bool descending);

};

