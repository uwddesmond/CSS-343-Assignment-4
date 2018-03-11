#pragma once
#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#included "movie.h"

using namespace std;

class Drama : public Movie {
	
public:
	Drama(int, string, string, string, string); // constructor
	bool operator<(const Movie&) const override; // less than operator

};

#endif // DRAMA_H