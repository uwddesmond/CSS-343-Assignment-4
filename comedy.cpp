// Dylan Desmond and Jimmy Lau
#include "comedy.h"

Comedy::Comedy(int stock, string title, string director,
	string releaseYear, string movieType) : 
	Movie(stock, title, director, releaseYear, movieType) {
}

bool Comedy::operator<(const Comedy &other) const
{
	if (this->title != other->title) {
		return this->title < other->title;
	}
	else {
		return this.releaseYear < other.releaseYear;
	}
}
