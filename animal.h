#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using std::string;

class Animal{

public:
	//Constructor
	Animal(int, double, int, int,  double, const string);
	//Destructor
	~Animal();
	
	//Set
	void setage(int);
	void setsize(double);
	void setx(int);
	void sety(int);
	void setgrow(double);
	
	//Get
	int getage() const;
	double getsize() const;
	double getgrow() const;
	int getx() const;
	int gety() const;
	string getname() const;
	
	//functions
	virtual void print();
	virtual string getCategory() const;
private:
	int age;
	double size;
	double grow;
	const string name;
	int x;
	int y;
	


};



#endif
