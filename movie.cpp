// Dylan Desmond and Jimmy Lau
// CSS 422
// This is the main Movie file that is inherited by the specific genres

#include "movie.h"
#include <string>

using namespace std;

// empty constructor
Movie::Movie() {

}

// constructor
Movie::Movie(int stock, string title, string director, string releaseYear) {

}
									
//~Movie(); // deconstructor
									
//string getMovieType();   // returns the type of movie

// decreases stock by 1
void Movie::decrementStock() {

}

// increases stock by 1
void Movie::incrementStock() {

}

// returns whether there is stock remaining
bool Movie::inStock() {

}

// returns the number of movies in stock
int Movie::getStockCount() {

}


// returns the title of the movie
string Movie::getTitle() {

}

// sets the title 
void Movie::setTitle() {

}

// returns the movie's director
string Movie::getDirector() {

}

// sets the director
void Movie::setDirector() {

}

// returns the movie's release year
string Movie::getReleaseData() {

}

// sets the movie's release year
void Movie::setReleaseData() {

}

// less than operator
bool Movie::operator<(const Movie &rhs) const {

}

// checks if the movies are the same
bool Movie::operator==(const Movie &rhs) const {

}