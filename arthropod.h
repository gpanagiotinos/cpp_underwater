#ifndef ARTHROPOD_H	
#define ARTHROPOD_H
#include "nonplakton.h"

class Arthropod : public Nonplakton
{
public:
	Arthropod(int, double, int, int,  double, const string,  double, double, double,  int);
	~Arthropod();

	virtual string getCategory() const;
};


#endif