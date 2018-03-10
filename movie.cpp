// Dylan Desmond and Jimmy Lau
// CSS 422
// This is the main Movie file that is inherited by the specific genres

#include "movie.h"
#include <string>

using namespace std;

// constructor
virtual Movie::Movie(int stock, string title, string director,
						string releaseYear, string movieType) {
	this.stockCount = stock;
	this.title = title;
	this.director = director;
	this.releaseYear = releaseYear;
	this.movieType = movieType;
}

// deconstructor
~Movie() {
	delete this*;
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
bool Movie::inStock() {
	return (stockCount > 0);
}

// returns the number of movies in stock
int Movie::getStockCount() {
	return stockCount;
}

// returns the title of the movie
string Movie::getTitle() {
	return title;
}

// returns the movie's director
string Movie::getDirector() {
	return director;
}

// returns the movie's release year
string Movie::getReleaseData() {
	return releaseYear;
}

string Movie::getMovieType() {
	return movieType;
}

// less than operator
virtual bool Movie::operator<(const Movie &rhs) const {

}