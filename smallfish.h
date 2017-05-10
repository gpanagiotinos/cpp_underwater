#ifndef SMALLFISH_H
#define SMALLFISH_H

#include "nonplakton.h"
class Smallfish : public Nonplakton{

public:
	//Constructor
	Smallfish(int, double, int, int,  double, const string,  double, double, double,  int);
	//Destructor
	~Smallfish();
	//function
	virtual string getCategory() const;

private:
	int dSmallfish;


};
#endif