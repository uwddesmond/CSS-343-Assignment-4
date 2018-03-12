#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <queue>
#include <deque>
#include "transaction.h"

using namespace std;

class Customer {

	public:
		Customer(int, string); // constructor recieves id, name
		~Customer(); // deconstructor

		int getCustomerId();		// returns the customer's id
		string getCustomerName();   // returns the customer's name
		void getHistory(); // returns a queue of the user's transactions

		void makeTransaction(Transaction*);
	
	private:
		int customerId;
		string name;
		deque<Transaction*>* history;
};

struct CustomerNode {
	CustomerNode* next;
	Customer* cust;

	CustomerNode(Customer* customer) {
		next = nullptr;
		cust = customer;
	}
};

#endif // CUSTOMER_H