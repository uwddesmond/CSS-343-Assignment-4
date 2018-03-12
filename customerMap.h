#pragma once
#ifndef CUSTOMERMAP_H
#define CUSTOMERMAP_H
#include <string>

#include "customer.h"

class customerMap {

public:
	customerMap();
	~customerMap();
	void insert(Customer*);
	Customer* find(int);

private:
	int hashFunction(int);
	CustomerNode* customers[10];

};


#endif // CUSTOMERMAP_H
