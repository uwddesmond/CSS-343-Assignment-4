#pragma once
#ifndef CLASSICS_H
#define CLASSICS_H

#include <string>
#include "movie.h"

class Classic : public Movie {

public :
	Classic(int, string, string, string, string, string); // constructor
	
	bool operator<(const Movie&) const override;

private :
	string actor;
};

#endif // CLASSICS_H