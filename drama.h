#pragma once
#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#included "movie.h"

using namespace std;

class Drama : public Movie {

public:
	bool operator<(const Movie&) const override; // less than operator

private:

};

#endif // DRAMA_H