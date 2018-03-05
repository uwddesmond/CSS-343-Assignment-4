#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <queue>
#include "transaction.cpp"

using namespace std;

class Customer {

	public:
		Customer(int, string); // constructor recieves id, name
		//~Customer(); // deconstructor

		int getCustomerId();		// returns the customer's id
		string getCustomerName();   // returns the customer's name
		Queue<Transaction> getHistory(); // returns a queue of the user's transactions
	
	private:
		int customerId;
		string name;
		Queue<Transaction> history;
};

#endif // CUSTOMER_H