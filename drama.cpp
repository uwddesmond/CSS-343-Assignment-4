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
bool Drama::operator<(const Drama &rhs) const {
	if (this->director != rhs.director) {
		this->director < rhs.director;
	}
	else {
		return this->title < rhs.title;
	}
}