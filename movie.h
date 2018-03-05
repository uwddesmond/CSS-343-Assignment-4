#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie {

	public:
		Movie(); // empty constructor
		Movie(int, string, string, string); // constructor
		//~Movie(); // deconstructor

		//string getMovieType();   // returns the type of movie

		void decrementStock();   // decreases stock by 1
		void incrementStock();   // increases stock by 1
		bool inStock();		     // returns whether there is stock remaining
		int getStockCount();     // returns the number of movies in stock

		string getTitle();	     // returns the title of the movie
		void setTitle();	     // sets the title 

		string getDirector();    // returns the movie's director
		void setDirector();      // sets the director

		string getReleaseData(); // returns the movie's release year
		void setReleaseData();   // sets the movie's release year

		bool operator<(const Movie&) const;  // less than operator
		bool operator==(const Movie&) const; // checks if the movies are the same 

	private:
		int stockCount;
		string title;
		string director;
		string releaseYear;
};

#endif // MOVIE_H