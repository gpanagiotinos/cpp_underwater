#include "arthropod.h"


Arthropod::Arthropod(int _age, double _size,int _x, int _y,  double _grow, string _name,  double _food_to_grow, double _weekfood, double _dayfood,  int _moves): Nonplakton(_age, _size, _x, _y,  _grow, _name, _food_to_grow, _weekfood, _dayfood, _moves){}


//function
string Arthropod::getCategory() const{
	return "Arthropod";
}