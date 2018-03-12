#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {

public:
	Transaction(int, string, bool); // constructor receives id, title, type
	~Transaction(); // deconstructor

	//int getCustomerId();		// returns the customer's id
	string getMovieTitle();     // returns the movie's title
	string transactionType();   // returns a string of what type of transaction it was

private:
	int custId;			// customer making the transaction's id
	string movieTitle;		// title of the movie
	bool returnOrBorrow;	// TRUE for a borrow and FALSE for a return transaction
};

#endif // TRANSACTION_H