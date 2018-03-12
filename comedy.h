#pragma once
#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "movie.h"
using namespace std;
class Comedy : public Movie {

public:
	Comedy(int, string, string, string, string);
	~Comedy();

	string getKey() const;
	bool operator<(const Comedy&) const;

private:
	string key;
};


#endif // COMEDY_H