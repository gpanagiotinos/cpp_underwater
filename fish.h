#ifndef FISH_H	
#define FISH_H
#include "nonplakton.h"

class Fish : public Nonplakton
{
public:
	Fish(int, double, int, int,  double, const string,  double, double, double,  int);
	~Fish();

	virtual string getCategory() const;
};


#endif