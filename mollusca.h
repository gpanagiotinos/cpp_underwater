#ifndef MOLLUSCA_H	
#define MOLLUSCA_H
#include "nonplakton.h"

class Mollusca : public Nonplakton
{
public:
	Mollusca(int, double, int, int,  double, const string,  double, double, double,  int);
	~Mollusca();


	virtual string getCategory() const;

};


#endif