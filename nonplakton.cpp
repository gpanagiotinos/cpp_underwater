#include "nonplakton.h"


//Constructor
Nonplakton::Nonplakton(int _age, double _size,int _x, int _y, double _grow, string _name, double _food_to_grow, double _weekfood, double _dayfood, int _moves): Animal( _age, _size, _x, _y, _grow, _name), food_to_grow(_food_to_grow), weekfood(_weekfood), dayfood(_dayfood), moves(_moves){}

//Set
void Nonplakton::setfood_to_grow(double _food_to_grow){

	food_to_grow = _food_to_grow;
}
void Nonplakton::setweekfood(double _weekfood){

	weekfood = _weekfood;
}
void Nonplakton::setdayfood(double _dayfood){

	dayfood = _dayfood;
}
void Nonplakton::setmoves(int _moves){

	moves = _moves;
}

//Get
double Nonplakton::getfood_to_grow() const{

	return food_to_grow;
}
double Nonplakton::getweekfood() const{

	return weekfood;
}
double Nonplakton::getdayfood() const{

	return dayfood;
}
int Nonplakton::getmoves() const{

	return moves;
}
//functions
string Nonplakton::getCategory() const{
	return "Nonplakton";
}
//Move change x , y of a nonplakton animal
void Nonplakton::move(int x, int y){
	setx(x);
	sety(y);
}

