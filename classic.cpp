// Dylan Desmond and Jimmy Lau
#include <string>
#include "classic.h"
using namespace std;
Classic::Classic(int stock, string title, string director,string releaseYear,
	string movieType, string actor) : Movie(stock, title, director, releaseYear, movieType) {
	this->actor = actor;
	this->key = releaseYear + actor;
}

Classic::~Classic()
{
	delete this;
}

string Classic::getKey() const
{
	return this->key;
}

bool Classic::operator<(const Classic &other) const
{
	if (this->releaseYear != other.getReleaseData()) {
		return this->releaseYear < other.getReleaseData();
	}
	else {
		return this->actor < other.actor;
	}
}
