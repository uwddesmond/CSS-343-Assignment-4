#pragma once
#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "movie.h"

class Comedy : public Movie {

public:

	bool operator<(const Movie&) const override;

};


#endif // COMEDY_H