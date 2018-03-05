#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {

public:
	Transaction(int, string, bool); // constructor receives id, title, type
	//~Transaction(); // deconstructor

	int getCustomerId();		// returns the customer's id
	string getMovieTitle();     // returns the movie's title
	string transactionType();   // returns a string of what type of transaction it was
	bool isDue();				// returns whether the movie is due or not

private:
	int customerId;			// customer making the transaction's id
	string movieTitle;		// title of the movie
	bool returnOrBorrow;	// TRUE for a borrow and FALSE for a return transaction
	int borrowTime;			// how much time is left before it is due
	int borrowPeriod;		// how long it has been borrowed for
};

#endif // TRANSACTION_H