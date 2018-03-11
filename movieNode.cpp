#include "movieNode.h"

template<class genre>
movieNode<genre>::movieNode(genre item)
{
	this->item = item;
	this->next = nullptr;
}