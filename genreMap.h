#pragma once
#ifndef GENEREMAP_H
#define GENEREMAP_H
#include <string>

template<class genre>
class genreMap {

public:
	void insert(genre*);
	genre* find(string);

private:
	int hashFunction(string);
	genre[] *movies;

};


#endif // GENREMAP_H
