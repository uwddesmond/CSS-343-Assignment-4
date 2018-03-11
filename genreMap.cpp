#include "genreMap.h"
#include <string>

template<class genre>
genreMap<genre>::genreMap<genre>()
{
	this->movies = new movieNode[10];
}

template<class genre>
void genreMap<genre>::insert(genre* movie)
{	
	int index = hashFunction(movie.getKey());
	movieNode* target = new MovieNode(movie);
	movieNode *cur = this->movies[index];
	if (cur != nullptr) {
		while (cur.next != nullptr) {
			cur = cur.next;
		}
		cur.next = target;
	}
	else {
		this->movies[index] = target;
	}
}

template<class genre>
genre * genreMap<genre>::find(string key)
{
	int index = hashFunction(key);
	movieNode *cur = this->movies[index];
	while (cur != nullptr) {
		if (key == cur.item.getKey()) {
			return cur.item;
		}
		cur = cur.next;
	}
	return nullptr;
}

template<class genre>
int genreMap<genre>::hashFunction(string key)
{
	return key.length() % 10;
}
