#include "plantplakton.h"

//Constructor
Plantplakton::Plantplakton( int _age, double _size,int _x, int _y, double _grow, string _name ): Animal( _age, _size, _x, _y, _grow, _name){}


//functions
string Plantplakton::getCategory() const{

	return "Plantplakton";
}