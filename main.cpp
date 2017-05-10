#include <iostream>
#include <typeinfo>
#include <string>
#include <cmath>
using namespace std;
#include "animal.h"
#include "mammal.h"
#include "plantplakton.h"
#include "arthropod.h"
#include "nonplakton.h"
#include "animalplakton.h"
#include "shellfish.h"
#include "smallfish.h"
#include "mollusca.h"
#include "seareptile.h"
#include "fish.h"
#include "definition.h"
#include "functions.cpp"



int main(){
	//Initialize map	
	init_map();
	//Start menu και έλεγχος αν ο χρήστης δίνει σωστή τιμή.
	//print(start_menu, START_MENU);
	int id;
	int quit = 1;
	int animal_id;
	int pause = 1;
	int day = 1;
	do{
	print(start_menu, START_MENU);
	id = user_input(start_menu, START_MENU);
	

	//Αρχικό switch επιλογών
	switch(id){
		// Start
		case 1:
		default_input();
		while(true){
			cout << "Day: " << day << endl;
			day++;
			print_map();
			operation();
			print_map();
			init_moves();
			//Εβδομάδες.
			if (day%7 == 0)
			{
				//Grow nonplakton animals
				grow();
				fun_wfood();
				print_info();

			}
			//Μήνας
			if (day%30==0)
			{
				//rise age and clean map from dead animals
				rise_age();

			}
			
			if (iskeypressed(500))
			{
				cout << "Pause" <<endl;
				break;
			}
			}
		break;
		// Resume
		case 2:
		while(true){
			cout << "Day: " << day << endl;
			day++;
			print_map();
			operation();
			print_map();
			init_moves();
			//Εβδομάδες.
			if (day%7 == 0)
			{
				//Grow nonplakton animals
				grow();
				fun_wfood();
				print_info();

			}
			//Μήνας
			if (day%30==0)
			{
				//rise age and clean map from dead animals
				rise_age();
			}
			print_info();
			if (iskeypressed(500))
			{
				cout << "Pause" <<endl;
				break;
			}
			}

		break;
		// Restart
		case 3:
		day = 1;
		init_table();
		init_map();
		print_map();
		default_input();
		while(true){
			cout << "Day: " << day << endl;
			day++;
			print_map();
			operation();
			print_map();
			init_moves();
			//Εβδομάδες.
			if (day%7 == 0)
			{
				//Grow nonplakton animals
				grow();
				fun_wfood();
				print_info();

			}
			//Μήνας
			if (day%30==0)
			{
				//rise age and clean map from dead animals
				rise_age();
			}
			print_info();
			if (iskeypressed(500))
			{
				cout << "Pause" <<endl;
				break;
			}
			}

		break;
		case 4:
		cout <<"Insert"<<endl;
		print(categories, CATEGORY);
		id = user_input(categories, CATEGORY);
		switch(id){
			case 1:
			print(plantplakton, PP_SIZE);
			animal_id = user_input(plantplakton, PP_SIZE);
			create(id, animal_id);
			break;
			case 2:
			print(animalplakton, AP_SIZE);
			animal_id = user_input(animalplakton, AP_SIZE);
			create(id, animal_id);
			break;
			case 3:
			print(shellfish, SF_SIZE);
			animal_id = user_input(shellfish, SF_SIZE);
			create(id, animal_id);
			break;
			case 4:
			print(arthropod, AR_SIZE);
			animal_id = user_input(arthropod, AR_SIZE);
			create(id, animal_id);
			break;
			case 5:
			print(mollusca, MO_SIZE);
			animal_id = user_input(mollusca, MO_SIZE);
			create(id, animal_id);
			break;
			case 6:
			print(smallfish, SMF_SIZE);
			animal_id = user_input(smallfish, SMF_SIZE);
			create(id, animal_id);
			break;
			case 7:
			print(seareptile, SR_SIZE);
			animal_id = user_input(seareptile, SR_SIZE);
			create(id, animal_id);
			break;
			case 8:
			print(fish, F_SIZE);
			animal_id = user_input(fish, F_SIZE);
			create(id, animal_id);
			break;
			case 9:
			print(mammal, MA_SIZE);
			animal_id = user_input(mammal, MA_SIZE);
			create(id, animal_id);
			break;
			default:
			cout <<"Unknown category Sorry!!!"<<endl;
		} 
		break;
		case 5:
		cout <<"Category Info"<<endl;
		int cat_info_id;
		int info_id;
		print(categories, CATEGORY);
		cat_info_id = user_input(categories, CATEGORY);
		print(cat_info, CAT_INFO);
		info_id = user_input(cat_info, CAT_INFO);
		print_cat_info(cat_info_id, info_id);
		break;
		case 6:
		print_animal_info();
		break;
		case 7:
		int factor_id;
		print(foreign_factors, FOR_FAC);
		factor_id = user_input(foreign_factors, FOR_FAC);
		affect_map(factor_id);
		break;
		case 8:
		print_exit_msg();
		quit = 0;
		break;
		default:
		cout<<"default"<<endl;
	}
}while(quit);


return 0;
}
