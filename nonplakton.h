#ifndef NONPLAKTON_H
#define NONPLAKTON_H
#include <string>
using std::string;
#include "animal.h"

class Nonplakton : public Animal{

	public:
		//Constructor
		Nonplakton(int, double, int, int,  double, const string,  double, double, double, int);	
		//Destructor
		~Nonplakton();
		//Set
		void setfood_to_grow(double);
		void setweekfood(double);
		void setdayfood(double);
		void setmoves(int);
		//Get
		double getfood_to_grow() const;
		double getweekfood() const;
		double getdayfood() const;
		int getmoves() const;
		//functions
		virtual string getCategory() const;
		void move(int , int);
		void eat(int, int, int , int);
				
	private:
		double food_to_grow; //Αναγκαία εβδομαδαία τροφή.
		double weekfood; //Ποσότητα τροφής που καταναλώθηκε την τρέχουσα εβδομάδα.
		double dayfood; //Ημερίασια ποσότητα φαγητού ώστε να είναι χορτασμένος ο οργανισμός.
		int moves; //Μέγιστος Αριθμός κινήσεων ανα ημέρα.
};
#endif
