#ifndef PLANTPLAKTON_H
#define PLANTPLAKTON_H
#include "animal.h"

class Plantplakton : public Animal{

	public:
		//Constructor
		Plantplakton(int, double, int, int, double, const string);
		//Destruction
		~Plantplakton();
		virtual string getCategory() const;
};
#endif
