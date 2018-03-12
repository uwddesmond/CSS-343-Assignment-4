// Dylan Desmond and Jimmy Lau

#include <string>
#include "drama.h"
using namespace std;
// drama movie constructor
Drama::Drama(int stock, string title, string director, string releaseYear, 
	string movieType) : Movie(stock, title, director, releaseYear, movieType) {
	this->key = director + title;
}

// deconstructor
Drama::~Drama() {
	delete this;
}

string Drama::getKey() const
{
	return this->key;
}

// less than operator
// Sorted by Director then Title alphabetically 
bool Drama::operator<(const Drama &rhs) const {
	if (this->director != rhs.director) {
		this->director < rhs.director;
	}
	else {
		return this->title < rhs.title;
	}
}