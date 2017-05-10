#ifndef SEAREPTILE_H	
#define SEAREPTILE_H
#include "nonplakton.h"

class Seareptile : public Nonplakton
{
public:
	Seareptile(int, double, int, int,  double, const string,  double, double, double,  int);
	~Seareptile();

virtual string getCategory() const;
};


#endif