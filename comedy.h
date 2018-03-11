#pragma once
#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "movie.h"

class Comedy : public Movie {

public:
	Comedy(int, string, string, string, string);

	bool operator<(const Comedy&) const;

};


#endif // COMEDY_H