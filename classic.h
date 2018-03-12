#pragma once
#ifndef CLASSICS_H
#define CLASSICS_H

#include <string>
#include "movie.h"
using namespace std;
class Classic : public Movie {

public :
	Classic(int, string, string, string, string, string); // constructor
	~Classic();

	string getKey() const;
	bool operator<(const Classic&) const;

private :
	string actor;
	string key;
};

#endif // CLASSICS_H