// Dylan Desmond and Jimmy Lau

#include "customerMap.h"
#include <string>
using namespace std;
// constructor
customerMap::customerMap() {

}

customerMap::~customerMap() {
	for (int i = 0; i < 10; ++i) {
		CustomerNode* current = customers[i];
		while (current != nullptr) {
			CustomerNode* temp = current;
			current = current->next;
			temp->next = nullptr;
			delete temp;
		}
	}
}

void customerMap::insert(Customer* customer)
{
	int index = hashFunction(customer->getCustomerId());
	CustomerNode* target = new CustomerNode(customer);
	CustomerNode *current = customers[index];
	if (current != nullptr) {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = target;
	}
	else {
		customers[index] = target;
	}
}

// Looks for a customer in the system based in their customer id
// If successfully found, a pointer to the customer node is returned
// If it fails and they do not exist in the system nullptr is returned
Customer* customerMap::find(int id)
{
	int index = hashFunction(id);
	CustomerNode* current = customers[index];
	while (current != nullptr) {
		if (current->cust->getCustomerId() == id) {
			return current->cust;
		}
		current = current->next;
	}
	return nullptr;
}

int customerMap::hashFunction(int id)
{
	return id % 10;
}