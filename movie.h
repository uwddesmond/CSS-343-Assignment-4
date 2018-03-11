#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie {

	public:
		Movie(int, string, string, string, string); // constructor
		~Movie(); // deconstructor

		void decrementStock();   // decreases stock by 1
		void incrementStock();   // increases stock by 1
		bool inStock();		     // returns whether there is stock remaining
		int getStockCount();     // returns the number of movies in stock

		string getTitle();	     // returns the title of the movie

		string getDirector();    // returns the movie's director

		string getReleaseData(); // returns the movie's release year

		string getMovieType();	 // returns the movie type

		virtual bool operator<(const Movie&) const;  // less than operator

	protected:
		int stockCount;
		string title;
		string director;
		string releaseYear;
		string movieType;
};

#endif // MOVIE_H