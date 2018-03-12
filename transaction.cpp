// Dylan Desmond and Jimmy Lau

#include "transaction.h"
#include <string>

using namespace std;

// constructor receives id, title, type
Transaction::Transaction(int customerId, string movieTitle, bool transType) {
	this->custId = customerId;
	this->movieTitle = movieTitle;
	this->returnOrBorrow = transType;
}

Transaction::~Transaction()
{
	delete this;
}


// returns the customer's id
//int Transaction::getCustomerId() {
//	return this->customerId;
//}

// returns the movie's title
string Transaction::getMovieTitle() {
	return this->movieTitle;
}

// returns a string of what type of transaction it was
string Transaction::transactionType() {
	if (this->returnOrBorrow) {
		return "B";
	}
	else {
		return "R";
	}
}

