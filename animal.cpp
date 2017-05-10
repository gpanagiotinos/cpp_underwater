#include "animal.h"

#include <iostream>
using namespace std;

//Constructor
Animal::Animal(int _age, double _size, int _x, int _y,  double _grow, const string _name):age(_age), size(_size), x(_x), y(_y), grow(_grow), name(_name){}


//Set
void Animal::setage(int _age){

	age = _age;
}
void Animal::setsize(double _size){

	size = _size;
}
void Animal::setx(int _x){

	x = _x;
}
void Animal::sety(int _y){

	y = _y;
}
void Animal::setgrow(double _grow){

	grow = _grow;
}

//Get

int Animal::getage() const{

	return age;
}
double Animal::getsize() const{

	return size;
}
int Animal::getx() const{

	return x;
}
int Animal::gety() const{

	return y;
}
double Animal::getgrow() const{

	return grow;
}
string Animal::getname() const{

	return name;
}

//functions

void Animal::print(){

	cout<<name<<"("<<x<<","<<y<<")"<<"|"<<"size:"<<size<<"|"<<"age:"<<age<<"|"<<endl;	

}

string Animal::getCategory() const{

	return "Animal";
}