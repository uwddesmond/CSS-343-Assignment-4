#pragma once
#ifndef GENEREMAP_H
#define GENEREMAP_H
#include <string>
#include "movieNode.h"
using namespace std;
template<class genre>
class genreMap {

public:
	genreMap<genre>();
	void insert(genre*);
	genre* find(string);
	void printInventory(string);

private:
	int hashFunction(string);
	movieNode<genre>* movies[10];

};


#endif // GENREMAP_H

