// Dylan Desmond and Jimmy Lau

#include <string>
#include "drama.h"

// drama movie constructor
Drama::Drama(int stock, string title, string director,
							string releaseYear, string movieType) {
	this.stockCount = stock;
	this.title = title;
	this.director = director;
	this.releaseYear = releaseYear;
	this.movieType = movieType;
}

// less than operator
// Sorted by Director then Title alphabetically 
virtual bool Drama::operator<(const Movie &rhs) const override {
	string director = getDirector();
	string otherDirector = rhs.getDirector();
	if (director < otherDirector) {
		return true;
	}
	else if (director > otherDirector) {
		return false;
	}

	string title = getTitle();
	string otherTitle = rhs.getTitle();

	if (title < otherTitle) {
		return true;
	}

	return false;

}