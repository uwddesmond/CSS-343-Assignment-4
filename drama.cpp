// Dylan Desmond and Jimmy Lau

#include <string>
#include "drama.h"

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