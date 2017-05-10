#ifndef MAMMAL_H
#define MAMMAL_H
#include "nonplakton.h"
class Mammal: public Nonplakton
{
public:
	//Constructor
	Mammal(int, double, int, int,  double, const string,  double, double, double,  int);
	//Destructor
	~Mammal();


	//function
	virtual string getCategory() const;

private:
	int dMammal;

};
#endif
