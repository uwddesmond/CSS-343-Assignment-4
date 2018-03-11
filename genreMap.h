#pragma once
#ifndef GENEREMAP_H
#define GENEREMAP_H
#include <string>
#include "movieNode.h"

template<class genre>
class genreMap {

public:
	genreMap<genre>();
	void insert(genre*);
	genre* find(string);

private:
	int hashFunction(string);
	movieNode[] *movies;

};


#endif // GENREMAP_H

