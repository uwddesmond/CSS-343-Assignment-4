// Dylan Desmond and Jimmy Lau
#include "comedy.h"

bool Comedy::operator<(const Movie other&) const
{
	if (this->title != other->title) {
		return this->getTitle < other->title;
	}
	else {
		return this.releaseYear < other.releaseYear;
	}
}
