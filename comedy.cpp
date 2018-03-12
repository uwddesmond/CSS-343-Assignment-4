// Dylan Desmond and Jimmy Lau
#include "comedy.h"
using namespace std;
Comedy::Comedy(int stock, string title, string director,
	string releaseYear, string movieType) : 
	Movie(stock, title, director, releaseYear, movieType) {
	this->key = title + releaseYear;
}

Comedy::~Comedy()
{
	delete this;
}

string Comedy::getKey() const
{
	return this->key;
}

bool Comedy::operator<(const Comedy &other) const
{
	if (this->title != other.title) {
		return this->title < other.title;
	}
	else {
		return this->releaseYear < other.releaseYear;
	}
}
