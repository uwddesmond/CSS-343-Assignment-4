#include "movieNode.h"
using namespace std;
template<class genre>
movieNode<genre>::movieNode(genre *item)
{
	this->item = item;
	this->next = nullptr;
}