// Dylan Desmond and Jimmy Lau

#include <string>
#include "drama.h"

// drama movie constructor
Drama::Drama(int stock, string title, string director, string releaseYear, 
	string movieType) : Movie(stock, title, director, releaseYear, movieType) {

}

// deconstructor
Drama::~Drama() {
	delete this;
}

// less than operator
// Sorted by Director then Title alphabetically 
virtual bool Drama::operator<(const Movie &rhs) const override {
	if (this->director < rhs->director) {
		return true;
	}
	else if (this->director > rhs->director) {
		return false;
	}

	if (this->title < rhs->title) {
		return true;
	}

	return false;

}