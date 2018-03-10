// Dylan Desmond and Jimmy Lau

#include "customer.h"
#include "transaction.cpp"
#include <string>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

// constructor
Customer::Customer(int customerId, string customerName) {
	this->customerId = customerId;
	this->name = customerName;
	this->history = new deque<Transaction>();
}

//~Customer(); // deconstructor

// returns the customer's id
int Customer::getCustomerId() {
	return this->customerId;
}

// returns the customer's name
string Customer::getCustomerName() {
	return this->name;
}

// returns a queue of the user's transactions
void Customer::getHistory() {
	deque<Transaction>::reverse_iterator trans = this->history->rbegin();
	for (trans; trans != history->rend(); ++trans) {
		Transaction cur = *trans;
		cout << cur.transactionType << ", " << cur.getMovieTitle;
	}
}