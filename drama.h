#pragma once
#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include "movie.h"

using namespace std;

class Drama : public Movie {
	
public:
	Drama(int, string, string, string, string); // constructor
	~Drama(); // Deconstructor

	string getKey() const;
	bool operator<(const Drama&) const; // less than operator

private:
	string key;
};

#endif // DRAMA_H