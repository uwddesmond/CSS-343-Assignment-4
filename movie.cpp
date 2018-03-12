// Dylan Desmond and Jimmy Lau
// CSS 422
// This is the main Movie file that is inherited by the specific genres

#include "movie.h"
#include <string>

using namespace std;

// constructor
Movie::Movie(int stock, string title, string director,
						string releaseYear, string movieType) {
	this->stockCount = stock;
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->movieType = movieType;
}

// deconstructor
Movie::~Movie() {
	delete this;
}
									
// decreases stock by 1
void Movie::decrementStock() {
	--stockCount;
}

// increases stock by 1
void Movie::incrementStock() {
	++stockCount;
}

// returns whether there is stock remaining
bool Movie::inStock() const {
	return (stockCount > 0);
}

// returns the number of movies in stock
int Movie::getStockCount() const {
	return stockCount;
}

// returns the title of the movie
string Movie::getTitle() const {
	return title;
}

// returns the movie's director
string Movie::getDirector() const {
	return director;
}

// returns the movie's release year
string Movie::getReleaseData() const {
	return releaseYear;
}

string Movie::getMovieType() const {
	return movieType;
}

// less than operator
bool Movie::operator<(const Movie &rhs) const {
	return false;
}