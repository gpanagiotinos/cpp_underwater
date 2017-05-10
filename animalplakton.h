#ifndef ANIMALPLAKTON_H
#define ANIMALPLAKTON_H

#include "nonplakton.h"

class Animalplakton : public Nonplakton{

	public:
		//Constructor
		Animalplakton(int, double, int, int,  double, const string,  double, double, double,  int);
		//Destructor
		~Animalplakton();
		//functions
		virtual string getCategory() const;


};
#endif
