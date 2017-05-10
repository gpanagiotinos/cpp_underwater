#ifndef SHELLFISH_H	
#define SHELLFISH_H
#include "nonplakton.h"

class Shellfish : public Nonplakton
{
public:
	Shellfish(int, double, int, int,  double, const string,  double, double, double,  int);
	~Shellfish();


	virtual string getCategory() const;
};


#endif