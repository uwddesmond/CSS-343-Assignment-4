#pragma once
#ifndef MOVIENODE_H
#define MOVIENODE_H

template <class genre>
class movieNode {
	
public:
	movieNode<genre>(genre*);

	movieNode* next;
	genre *item;

};

#endif // MOVIENODE_H
