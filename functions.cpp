#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <poll.h>

using namespace std;
//Pause function
bool iskeypressed(unsigned timeout_ms = 0){
	struct pollfd press[1];
	press[0].fd = STDIN_FILENO;
	press[0].events = POLLIN | POLLPRI;
	return poll(press, 1, timeout_ms);
}

//Initialize map
void init_map(){
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			map[i][j] = 0;
		}
	}
}
//Initialize table
void init_table(){
	for (int i = 0; i < CATEGORY-1; ++i)
	{
		dead_table[i] = 0;
		wfood[i] = 0;
	}
}

//Default Input
void default_input(){
	//Plantplakton
	int randy , randx, animal_id;
	// cout <<"default_input"<<endl; (DEBUG)
	// Create def plantplakton
	srand(time(0));
	for (int i = 0; i < PLANTPLAKTON; ++i)	
	{	
		animal_id = rand() % PP_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Plantplakton((int)def_pp[animal_id][0], def_pp[animal_id][1], randx, randy,  def_pp[animal_id][2], plantplakton[animal_id]);
		fill_area(animal_id, randx, randy);
	}
	//Create def animalplakton
	for (int i = 0; i < ANIMALPLAKTON; ++i)
	{
		animal_id = rand() % AP_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Animalplakton((int)def_ap[animal_id][0], def_ap[animal_id][1], randx, randy,   def_ap[animal_id][2], animalplakton[animal_id], def_ap[animal_id][3], def_ap[animal_id][4], def_ap[animal_id][5], (int)def_ap[animal_id][6]);
	}
	//Create def shellfish
	for (int i = 0; i < SHELLFISH; ++i)
	{
		animal_id = rand() % SF_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Shellfish((int)def_sf[animal_id][0], def_sf[animal_id][1], randx, randy, def_sf[animal_id][2], shellfish[animal_id], def_sf[animal_id][3], def_sf[animal_id][4], def_sf[animal_id][5], (int)def_sf[animal_id][6]);
	}
	//Create def arthropod
	for (int i = 0; i < ARTHROPOD; ++i)
	{
		animal_id = rand() % AR_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Arthropod((int)def_ar[animal_id][0], def_ar[animal_id][1], randx, randy, def_ar[animal_id][2], arthropod[animal_id], def_ar[animal_id][3], def_ar[animal_id][4], def_ar[animal_id][5], (int)def_ar[animal_id][6]);
	}
	//Create def mollusca
	for (int i = 0; i < MOLLUSCA; ++i)
	{
		animal_id = rand() % MO_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Mollusca((int)def_mo[animal_id][0], def_mo[animal_id][1], randx, randy, def_mo[animal_id][2], mollusca[animal_id], def_mo[animal_id][3], def_mo[animal_id][4], def_mo[animal_id][5], (int)def_mo[animal_id][6]);
	}
	//Create def smallfish
	for (int i = 0; i < SMALLFISH; ++i)
	{
		animal_id = rand() % SMF_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Smallfish((int)def_smf[animal_id][0], def_smf[animal_id][1], randx, randy, def_smf[animal_id][2], smallfish[animal_id], def_smf[animal_id][3], def_smf[animal_id][4], def_smf[animal_id][5], (int)def_smf[animal_id][6]);
	}
	//Create def seareptile
	for (int i = 0; i < SEAREPTILE; ++i)
	{
		animal_id = rand() % SR_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Seareptile((int)def_sr[animal_id][0], def_sr[animal_id][1], randx, randy, def_sr[animal_id][2], seareptile[animal_id], def_sr[animal_id][3], def_sr[animal_id][4], def_sr[animal_id][5], (int)def_sr[animal_id][6]);
	}
	//Create def fish
	for (int i = 0; i < FISH; ++i)
	{
		animal_id = rand() % F_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Fish((int)def_f[animal_id][0], def_f[animal_id][1], randx, randy, def_f[animal_id][2], fish[animal_id], def_f[animal_id][3], def_f[animal_id][4], def_f[animal_id][5], (int)def_f[animal_id][6]);
	}
	//Create def mammal
	for (int i = 0; i < MAMMAL; ++i)
	{
		animal_id = rand() % MA_SIZE;
		rand_position(randx, randy);
		map[randx][randy] = new Mammal((int)def_ma[animal_id][0], def_ma[animal_id][1], randx, randy, def_ma[animal_id][2], mammal[animal_id], def_ma[animal_id][3], def_ma[animal_id][4], def_ma[animal_id][5], (int)def_ma[animal_id][6]);
	}

	
}
//Exit message
void print_exit_msg(){
	cout <<"	~~~~Ceid Sea~~~~"<<endl;
	cout <<"	    Good-bye    "<<endl;
	cout <<"	~~~~~~~~~~~~~~~~"<<endl;
}

//Print map
void print_map(){
	//Title
	int waves;
	int id;
	waves = (COLUMN-8)/2;
	waves = fabs(waves);
	for (int i = 0; i < waves; ++i)
	{
		cout<<"*";
	}
	cout <<"Ceid Sea";
	for (int i = 0; i < waves; ++i)
	{
		cout<<"*";
	}
	cout << endl;

	//Map
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
			{	
				if(map[i][j] == 0){
					cout <<"~";
				}else{
					id = find_symbol(i,j);
					cout << symbol[id];
				}
				

			}
			cout <<endl;	
	}
	for (int i = 0; i < COLUMN; ++i)
	{
		cout << "*";
	}
	cout <<endl;
}
//Print Animal Info
void print_info(){

	
	for (int i = 0; i < CATEGORY; ++i)
	{
		if(categories[i]!="Plantplakton" && categories[i]!="Animalplakton"){
			cout <<categories[i]<<": "<<endl;
			for (int j = 0; j < ROW; ++j)
			{
				for (int k = 0; k < COLUMN; ++k)
				{	
					Nonplakton *animal = dynamic_cast <Nonplakton*>(map[j][k]);
					if(map[j][k] && (map[j][k]->getCategory() == categories[i])){
						cout<<map[j][k]->getname()<<"("<<map[j][k]->getx()<<", "<<map[j][k]->gety()<<")"<<"age: "<<map[j][k]->getage()<<" size: "<<map[j][k]->getsize()<<endl;
					}
				}
			}
		}
		// if(i>1){
		// 	cout<<"death's "<<dead_table[i-1]<<endl;
		// }		
	}
}
//Category Info function.
void print_cat_info(int cat_info_id ,int info_id){
	string category_name;
	category_name = categories[cat_info_id - 1];
	int count = 0;
	int sum = 0;
	double avg = 0;
	int dead = 0;
	double rate = 0.0;
	switch(info_id){
		case 1:
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLUMN; ++j)
			{
				if (map[i][j]!=0)		
				{
					if (map[i][j]->getCategory() == category_name )
					{
						sum += map[i][j]->getsize();
						count++;

					}
				}
			}
		}
		if (count)
		{
			avg = sum/count;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<category_name << "\nAverage Size: "<<avg<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl; 
		}else{
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<"Category "<<category_name<<" has disapeared from the sea"<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
		}
		break;
		case 2:
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLUMN; ++j)
			{
				if (map[i][j]!=0)		
				{
					if (map[i][j]->getCategory() == category_name )
					{
						count++;

					}
				}
			}
		}
		if (count)
		{
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<category_name << "\nPopulation: "<<count<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl; 
		}else{
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<"Category "<<category_name<<" has disapeared from the sea"<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
		}
		break;
		case 3:
		if(category_name != "Plantplakton"){
			for (int i = 0; i < ROW; ++i)
			{
				for (int j = 0; j < COLUMN; ++j)
				{
					if (map[i][j]!=0)		
					{
						if (map[i][j]->getCategory() == category_name )
						{
							count++;

						}
					}
				}
			}
			if (count)
			{
				avg = wfood[cat_info_id-2]/count;
				cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout <<category_name << "\nAverage consumption: "<<avg<<endl;
				cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl; 
			}else{
				cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout <<"Category "<<category_name<<" has disapeared from the sea"<<endl;
				cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
			}

			}else{
				cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout <<"Plantplakton plant grow without food!!!"<<endl;
				cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
			}
		break;
		case 4:
		for (int i = 0; i < CATEGORY-1; ++i)
		{
			dead +=dead_table[i];
		}
		if (dead)
		{
			rate = ((100*dead_table[cat_info_id-2])/dead);
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<category_name << "\nMortality rate: "<<rate<<'%'<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl; 
		}else{
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<"Non dead animal in the sea!!!"<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
		}
		
		break;
		case 5:
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLUMN; ++j)
			{
				if (map[i][j]!=0)		
				{
					if (map[i][j]->getCategory() == category_name )
					{
						sum += map[i][j]->getage();
						count++;

					}
				}
			}
		}
		if (count)
		{
			avg = sum/count;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<category_name << "\nAverage Age: "<<avg<<" month(s)"<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl; 
		}else{
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout <<"Category "<<category_name<<" has disapeared from the sea"<<endl;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
		}
		break;
		default:
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout <<"Can't find the information that you want. Sorry!!!"<<endl;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
		break;
	}
}
//Animal Info
void print_animal_info(){
	int pos_x, pos_y;
	int wrong;
	int false_var = 0;
	string name;
	do
	{
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		print_info();
		wrong = 0;
		cout <<"\nWrite the name of the animal that you want to see info> ";
		cin >> name;
		cout <<"\nWrite the row number that the animal is> ";
		cin >> pos_x;
		cout <<"\nWrite the column number that the animal is> ";
		cin >> pos_y;
		
		if (map[pos_x][pos_y] == 0)
		{	
			false_var = 1;
			wrong = 1;
		}else if(map[pos_x][pos_y]->getname() != name){
			false_var = 2;
			wrong = 1;
		}
		if(wrong){
			switch(false_var){
			case 1:
			cout <<"\nWrong position!!! At ("<<pos_x<<", "<<pos_y<<")"<<"there's not an animal. Try Again :)\n"<<endl;
			break;
			case 2:
			cout <<"\nWrong name!!! The animal "<<name<<" must be in a different position. Try Again :)\n"<<endl;
			break;
			default:
			cout <<"\nUnknown Error!!! Try Again :)\n"<<endl;
			break;
			}
		}
	} while (wrong);
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;

	//Animal Info
	if (map[pos_x][pos_y]->getCategory() == "Plantplakton")	
	{
		cout <<"~~~~~~~~~Plant Info~~~~~~~~~"<<endl;
		cout <<"Category: "<<map[pos_x][pos_y]->getCategory()<<endl;
		cout <<"Name: "<<map[pos_x][pos_y]->getname()<<endl;
		cout <<"Age: "<<map[pos_x][pos_y]->getage()<<"month(s)"<<endl;
		cout <<"Size: "<<map[pos_x][pos_y]->getsize()<<endl;
		cout <<"Grow number: "<<map[pos_x][pos_y]->getgrow()<<endl;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
	}else{
		Nonplakton *info_animal = dynamic_cast <Nonplakton*>(map[pos_x][pos_y]);
		cout <<"~~~~~~~~~Animal Info~~~~~~~~~"<<endl;
		cout <<"Category: "<<info_animal->getCategory()<<endl;
		cout <<"Name: "<<info_animal->getname()<<endl;
		cout <<"Age: "<<info_animal->getage()<<" month(s)"<<endl;
		cout <<"Size: "<<info_animal->getsize()<<endl;
		cout <<"Grow number: "<<info_animal->getgrow()<<endl;
		cout <<"Food to grow number: "<<info_animal->getfood_to_grow()<<endl;
		cout <<"Week food: "<<info_animal->getweekfood()<<endl;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
	}
	


}



void print(string table[], int rows){
	int count;
	cout <<"~~~~~Welcome to Ceid Sea~~~~~"<<endl;
	cout <<"(Write one choise of the menu and press \"Enter\" )"<<endl;
	for (int i = 0; i < rows; ++i)
	{	count = i;
		cout << ++count << ")" << table[i]<< endl;
	}
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl; 
}
//Ελεγχός για το αν ο χρήστης έδωσε τιμή που περιέχετε στο μενού επιλογών.  
int check(string choose, string table[], int rows){
int flag = 0;
for (int i = 0; i < rows; ++i)
{
	if (choose == table[i])
	{
		flag = (i + 1);
	}
}
if(flag){
	return flag;
}else{
	return 0;
}
}


//Είσοδος απο τον χρήστη.

int user_input(string table[], int rows){
	string choose; //Είσοδος του χρήστη.
	int wrong;//Flag για το αν ο χρήστης έδωσε σωστή ή λάθος τιμή.
	int id;//id τής κάθε πιθανής επιλογής του χρήστη(χρησιμοποιήτε στην switch).
	do
	{
		cin >> choose;
		wrong = 0;
		id = check(choose, table, rows);
		if(!id){
		cout << choose << " Its not valid choose please try again\n" <<endl;
		wrong = 1;
		print(table, rows);
	}
	
	} while(wrong);
	return id;

}
//Δημιουργεία αντικειμένου.
void create(int id, int animal_id){

//Constructor Name:
	string constr_name;
//Animal Name
	string animal_name;
//flags
	int empty;
	int pos;
//Position
	int x, y;
	do
	{
		cout << "Write the row that you want to be your animal in map: ";
		cin >> x;
		cout << "Write the column that you want to be your animal in map: "; 
		cin >> y;
		empty = 0;
		pos = check_position(x, y);
		if(!pos){
			cout <<"The post (" << x << ", " << y << ") its not empty or out of range" <<endl;
		empty = 1;
	}
	} while (empty);
	switch (id){
		case 1:
			map[x][y] = new Plantplakton((int)def_pp[animal_id][0], def_pp[animal_id][1], x, y,  def_pp[animal_id][2], plantplakton[animal_id]);
			fill_area(animal_id, x, y);
			print_map();
		break;
		case 2:
			map[x][y] = new Animalplakton((int)def_ap[animal_id][0], def_ap[animal_id][1], x, y,   def_ap[animal_id][2], animalplakton[animal_id], def_ap[animal_id][3], def_ap[animal_id][4], def_ap[animal_id][5], (int)def_ap[animal_id][6]);
			print_map();

		break;
		case 3:
			map[x][y] = new Shellfish((int)def_sf[animal_id][0], def_sf[animal_id][1], x, y, def_sf[animal_id][2], shellfish[animal_id], def_sf[animal_id][3], def_sf[animal_id][4], def_sf[animal_id][5], (int)def_sf[animal_id][6]);
			print_map();
		break;
		case 4:
			map[x][y] = new Arthropod((int)def_ar[animal_id][0], def_ar[animal_id][1], x, y, def_ar[animal_id][2], arthropod[animal_id], def_ar[animal_id][3], def_ar[animal_id][4], def_ar[animal_id][5], (int)def_ar[animal_id][6]);
			print_map();
		break;
		case 5:
			map[x][y] = new Mollusca((int)def_mo[animal_id][0], def_mo[animal_id][1], x, y, def_mo[animal_id][2], mollusca[animal_id], def_mo[animal_id][3], def_mo[animal_id][4], def_mo[animal_id][5], (int)def_mo[animal_id][6]);
			print_map();
		break;
		case 6:
			map[x][y] = new Smallfish((int)def_smf[animal_id][0], def_smf[animal_id][1], x, y, def_smf[animal_id][2], smallfish[animal_id], def_smf[animal_id][3], def_smf[animal_id][4], def_smf[animal_id][5], (int)def_smf[animal_id][6]);
			print_map();
		break;
		case 7:
			map[x][y] = new Seareptile((int)def_sr[animal_id][0], def_sr[animal_id][1], x, y, def_sr[animal_id][2], seareptile[animal_id], def_sr[animal_id][3], def_sr[animal_id][4], def_sr[animal_id][5], (int)def_sr[animal_id][6]);
			print_map();
		break;
		case 8:
			map[x][y] = new Fish((int)def_f[animal_id][0], def_f[animal_id][1], x, y, def_f[animal_id][2], fish[animal_id], def_f[animal_id][3], def_f[animal_id][4], def_f[animal_id][5], (int)def_f[animal_id][6]);
			print_map();
		break;
		case 9:
			map[x][y] = new Mammal((int)def_ma[animal_id][0], def_ma[animal_id][1], x, y, def_ma[animal_id][2], mammal[animal_id], def_ma[animal_id][3], def_ma[animal_id][4], def_ma[animal_id][5], (int)def_ma[animal_id][6]);
			print_map();
		break;
		default:
		cout <<"Cannot create the animal. Sorry!!!"<<endl;
	}

}
//Γέμισμα μιας περιοχής με φυτοπλαγκτον.
void fill_area(int animal_id, int x, int y){
	int start_x = x-1;
	int start_y = y-1;
	for (int i = start_x; i < x+2; ++i)
	{
		for (int j = start_y; j < y+2; ++j)
		{
			if(check_position(i, j)){
				map[i][j] = new Plantplakton((int)def_pp[animal_id][0], def_pp[animal_id][1], i, j,  def_pp[animal_id][2], plantplakton[animal_id]);
			}
		}
	}

}


// Αναζήτηση για τι κατηγορία είναι το συγκεκριμένο αντικείμενο στον χάρτη.
int find_symbol(int i, int j){
	string category;
	int id;
	category = map[i][j]->getCategory();
	for (int k = 0; k < CATEGORY; ++k)
	{
		if (category == categories[k])
		{
			id = k;
		}
	}
	return id;

}

 void rand_position(int &randx, int &randy){
 	
 	srand(time(0));
 	do{
 	randx = rand() % ROW;
 	randy = rand() % COLUMN;
 	}while(!check_position(randx, randy));
 }
 //Ελέγχος αν μια θέση είναι κενή
int check_position (int x, int y){

	if ((x<ROW && x>-1) && (y<COLUMN && y>-1))
	{
		
		return !map[x][y] ? 1 : 0;
	}else{
		//cout<<"Here"<<endl;
		return 0;
	}
}
//Τυχαία λειτουργία
void rand_move(int &x, int &y){
	int newx = 0;
	int newy = 0;
	int select = 0;
	srand(time(0));
	do{
		select = 1 + rand()%8;
		switch(select){
			case 1:
			newx = x-1;
			newy = y-1;
			break;
			case 2:
			newx = x-1;
			newy = y;
			break;
			case 3:
			newx = x-1;
			newy = y+1;
			break;
			case 4:
			newx = x;
			newy = y-1;
			break;
			case 5:
			newx = x;
			newy = y+1;
			break;
			case 6:
			newx = x+1;
			newy = y-1;
			break;
			case 7:
			newx = x+1;
			newy = y;
			break;
			case 8:
			newx = x+1;
			newy = y+1;
			break;

		}
	}while((newx>(ROW-1) || newx<0)||(newy>(COLUMN-1) || newy<0));
	x = newx;
	y = newy;
}
int choose_move(int x , int y, int oldx, int oldy){
	Nonplakton *move_animal = dynamic_cast <Nonplakton*>(map[oldx][oldy]);
	if(map[x][y] == 0){
		move_animal->move(x, y);
		map[x][y] = move_animal;
		map[oldx][oldy] = 0;
		return 0;
	}else if(eat(x, y, oldx, oldy)){
		move_animal->move(x, y);
		death(x,y);
		map[x][y] = 0;
		map[x][y] = move_animal;
		map[oldx][oldy] = 0;
		return 0;
	}else if(multiplication(x, y, oldx, oldy)){
	 	return 0;
	}

	return 1;
}
int eat(int foodx, int foody, int x, int y){
	int category_id=0;

	for (int i = 0; i < CATEGORY; ++i)
	{
		if(map[x][y]->getCategory() == categories[i]){
			category_id = i;

		}
	}

	for (int j = 0; j < 5; ++j)
	{	
		if(map[foodx][foody]->getCategory() == food_cat[category_id-1][j]){
			Nonplakton *eat_animal = dynamic_cast <Nonplakton*>(map[x][y]);
			eat_animal->setdayfood(map[foodx][foody]->getsize() + eat_animal->getdayfood());
			return 1;
		}
	}
	return 0;

}
int multiplication(int x, int y, int oldx, int oldy){
	if(map[oldx][oldy]->getCategory() != "Animalplakton"){
		if ((map[oldx][oldy]->getCategory() == map[x][y]->getCategory())&&(map[oldx][oldy]->getsize() == map[x][y]->getsize())&&(map[oldx][oldy]->getname() == map[x][y]->getname())&&map[oldx][oldy]->getsize()>2.0 && map[x][y]->getsize()>2.0 && map[oldx][oldy]->getage()>1 && map[x][y]->getage()>1)
		{
			int start_oldx = oldx-1;
			int start_oldy = oldy-1;
			int start_x;
			int start_y;
			for (int i = start_oldx; i < oldx+2; ++i)
			{
				for (int j = start_oldy; j < oldy+2; ++j)
				{
					if(check_position(i, j)){
						new_animal(i, j, oldx, oldy);
						
						return 1;
					}
					if((i == x) && (j == y) ){
						int start_x = x-1;
						int start_y = y-1;
						for (int n = start_x; n < x+2; ++n)
						{
							for (int k = start_y; k < y+2; ++k)
							{
								if(check_position(n, k)){
									new_animal(n,k, oldx, oldy);
									return 1;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
void new_animal(int x, int y, int parent_x, int parent_y){
	int cat_id;
	int animal_id;

	for (int i = 2; i < CATEGORY; ++i)
	{
		if(map[parent_x][parent_y]->getCategory() == categories[i]){
			cat_id = i+1;
		}
	}
	switch (cat_id){
		case 3:
			for (int j = 0; j < SF_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == shellfish[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Shellfish((int)def_sf[animal_id][0], def_sf[animal_id][1], x, y, def_sf[animal_id][2], map[parent_x][parent_y]->getname(), def_sf[animal_id][3], def_sf[animal_id][4], def_sf[animal_id][5], (int)def_sf[animal_id][6]);
		
		break;
		case 4:
			for (int j = 0; j < AR_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == arthropod[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Arthropod((int)def_ar[animal_id][0], def_ar[animal_id][1], x, y, def_ar[animal_id][2], map[parent_x][parent_y]->getname(), def_ar[animal_id][3], def_ar[animal_id][4], def_ar[animal_id][5], (int)def_ar[animal_id][6]);
			
		break;
		case 5:
			for (int j = 0; j < MO_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == mollusca[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Mollusca((int)def_mo[animal_id][0], def_mo[animal_id][1], x, y, def_mo[animal_id][2], map[parent_x][parent_y]->getname(), def_mo[animal_id][3], def_mo[animal_id][4], def_mo[animal_id][5], (int)def_mo[animal_id][6]);
		break;
		case 6:
			for (int j = 0; j < SMF_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == smallfish[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Smallfish((int)def_smf[animal_id][0], def_smf[animal_id][1], x, y, def_smf[animal_id][2], map[parent_x][parent_y]->getname(), def_smf[animal_id][3], def_smf[animal_id][4], def_smf[animal_id][5], (int)def_smf[animal_id][6]);
		break;
		case 7:
			for (int j = 0; j < SR_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == seareptile[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Seareptile((int)def_sr[animal_id][0], def_sr[animal_id][1], x, y, def_sr[animal_id][2], map[parent_x][parent_y]->getname(), def_sr[animal_id][3], def_sr[animal_id][4], def_sr[animal_id][5], (int)def_sr[animal_id][6]);
		break;
		case 8:
		for (int j = 0; j < F_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == fish[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Fish((int)def_f[animal_id][0], def_f[animal_id][1], x, y, def_f[animal_id][2], map[parent_x][parent_y]->getname(), def_f[animal_id][3], def_f[animal_id][4], def_f[animal_id][5], (int)def_f[animal_id][6]);
		break;
		case 9:
		for (int j = 0; j < MA_SIZE; ++j)
			{
				if(map[parent_x][parent_y]->getname() == mammal[j]){
					animal_id = j;
				}
			}
			map[x][y] = new Mammal((int)def_ma[animal_id][0], def_ma[animal_id][1], x, y, def_ma[animal_id][2], map[parent_x][parent_y]->getname(), def_ma[animal_id][3], def_ma[animal_id][4], def_ma[animal_id][5], (int)def_ma[animal_id][6]);
		break;
		default:
		cout <<"Cannot create the animal. Sorry!!!"<<endl;
	}
}


//Λειτουργίες κάθε ζώου.
void operation(){
	int x, y, oldx, oldy;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			if (map[i][j]!=0)
			{
				Nonplakton *animal = dynamic_cast <Nonplakton*>(map[i][j]);
				if (map[i][j]->getCategory() != "Plantplakton" && animal->getmoves())
				{	
					
					x = i;
					y = j;
					oldx = i;
					oldy = j;
					do{
						//Πέρασμα τιμής ώστε να χρησιμοποιήθη το x,y ως δείκτης.
						do{
							rand_move(x, y);
						}while(choose_move(x, y, oldx, oldy));
						animal->setmoves(animal->getmoves()-1);
						oldx = x;
						oldy = y;
					}while(animal->getmoves());
				}else if(map[i][j]->getCategory() == "Plantplakton"){
					map[i][j]->setsize(map[i][j]->getsize()+map[i][j]->getgrow());
				}
			}
		}
	}				
}

//Τέλος της ημέρας => αρχικοποίηση των moves κάθε ζώου.
void init_moves(){
	
	int id;
	string category;
	int animal_name;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			if(map[i][j]!=0){
				category = map[i][j]->getCategory();
				if (category!="Plantplakton")
				{
					
					for (int k = 0; k < CATEGORY; ++k)
					{
						if (category == categories[k])
						{
							id = k;
						}
					}
					Nonplakton *animal = dynamic_cast <Nonplakton*> (map[i][j]);
					switch(id){
						case 1:
							
							for (int n = 0; n < AP_SIZE; ++n)
							{
								if(animal->getname() == animalplakton[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_ap[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_ap[animal_name][5]);
						break;
						case 2:
							for (int n = 0; n < SF_SIZE; ++n)
							{
								if(animal->getname() == shellfish[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_sf[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_sf[animal_name][5]);

						break;
						case 3:
							for (int n = 0; n < AR_SIZE; ++n)
							{
								if(animal->getname() == arthropod[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_ar[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_ar[animal_name][5]);
						break;
						case 4:
							for (int n = 0; n < MO_SIZE; ++n)
							{
								if(animal->getname() == mollusca[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_mo[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_mo[animal_name][5]);
						break;
						case 5:
							for (int n = 0; n < SMF_SIZE; ++n)
							{
								if(animal->getname() == smallfish[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_smf[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_smf[animal_name][5]);
						break;
						case 6:
							for (int n = 0; n < SR_SIZE; ++n)
							{
								if(animal->getname() == seareptile[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_sr[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_sr[animal_name][5]);
						break;
						case 7:
							for (int n = 0; n < F_SIZE; ++n)
							{
								if(animal->getname() == fish[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_f[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_f[animal_name][5]);
						break;
						case 8:
							for (int n = 0; n < MA_SIZE; ++n)
							{
								if(animal->getname() == mammal[n]){
									animal_name = n;
								}
							}
							animal->setmoves(def_ma[animal_name][6]);
							animal->setweekfood(animal->getweekfood() + animal->getdayfood());
							animal->setdayfood(def_ma[animal_name][5]);

						break;
						default:
						cout <<"Cannot init moves of the animal. Sorry!!!"<<endl;
					}
				}
					
			}
		}
	}
}

//Ανάπτυξη μέγεθους ζώου.
void grow(){
	double percentage;
	double check;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			if (map[i][j]!=0)	
			{
				if (map[i][j]->getCategory() != "Plantplakton")
				{
					Nonplakton *grow_animal = dynamic_cast <Nonplakton*> (map[i][j]);
					if(grow_animal->getweekfood() >= grow_animal->getfood_to_grow()){
						grow_animal->setsize(grow_animal->getsize()+grow_animal->getgrow());
					}else{
						percentage = ((1*grow_animal->getweekfood())/grow_animal->getfood_to_grow());
						if(percentage<0,2){
							check = (grow_animal->getsize()-(grow_animal->getgrow()/percentage));
							if(check<=0){
								grow_animal->setsize(0);
							}else{
								grow_animal->setsize(check);	
							}
						}else{
							grow_animal->setsize(grow_animal->getsize()+(grow_animal->getgrow()/percentage));
						}
					}
				}
			}
		}
	}
}

void rise_age(){
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			if (map[i][j]!=0)
			{
				if (map[i][j]->getsize()!=0)
				{
					map[i][j]->setage(map[i][j]->getage()+1);
				}else{
					death(i,j);
					map[i][j]=0;
				}
			}
		}
	}
}

void death(int x, int y){
	for (int i = 1; i < CATEGORY; ++i)
	{
		if (map[x][y]->getCategory() == categories[i])
		{
			dead_table[i-1] = dead_table[i-1] + 1;
		}
	}
}

void fun_wfood(){
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{	

			if (map[i][j]!=0&& map[i][j]->getCategory()!="Plantplakton")	
			{
				for (int n = 1; n < CATEGORY; ++n)
				{
					if(map[i][j]->getCategory() == categories[n]){
						Nonplakton *wfood_animal = dynamic_cast <Nonplakton*> (map[i][j]);
						wfood[n-1] = wfood[n-1] + wfood_animal->getweekfood();
						wfood_animal->setweekfood(0.0);
					}
				}
			}
		}
	}
}

//Foreign Factors function
void affect_map(int factor_id){
	//Infection
	int cell, x, y, i, infx, infy;
	int count;
	int cell_count = 1;
	//Nets
	int net, r, c, j, netx, nety;
	int net_count = 1;
	int count_2;
	switch(factor_id){
		case 1:
		do{
			cout << "Write the row that you want to start the infection> ";
			cin >> x;
			if (x>ROW || x<0)
			{
				cout <<"\n"<<x<< " is invalid value for row!!!\n The correct values is between "<<ROW<< "and 0"<<endl;
			}
		}while(x>ROW || x<0);
		do{
			cout << "Write the column that you want to start the infection> "; 
			cin >> y;
			if (y>COLUMN || y<0)
			{
				cout <<"\n"<<y<< " is invalid value for column!!!\n The correct values is between "<<COLUMN<< "and 0"<<endl;
			}
		}while(y>COLUMN || y<0);
		do{
			cout <<"Give me the size of infection.(How many cells affects)> ";
			cin >> cell;
			if (cell>40 || cell<1)
			{
				cout <<"\n"<<cell<< " is invalid value for cells!!!\n The correct values is between 1 and 40"<<endl;
			}
		}while(cell>40 || cell<1);
				i = 1;
				count = 1;
				cout <<"~~~~~~~~Polluted Fish~~~~~~~~"<<endl;
				if(map[x][y] != 0){
					if (map[x][y]->getCategory()!="Plantplakton")
					{
						death(x, y);
					}
					map[x][y] = 0;
				}
					do
					{
						switch(count){
							case 1:
							infx = x-i;
							infy = y-i;
							break;
							case 2:
							infx = x-i;
							infy = y;
							break;
							case 3:
							infx = x-i;
							infy = y+i;
							break;
							case 4:
							infx = x;
							infy = y-i;
							break;
							case 5:
							infx = x;
							infy = y+i;
							break;
							case 6:
							infx = x+i;
							infy = y-i;
							break;
							case 7:
							infx = x+i;
							infy = y;
							break;
							case 8:
							infx = x+i;
							infy = y+i;
							break;

						}
						count++;
						cell_count++;
						if(count>8 && cell_count < (cell+1)){
							count = 1;
							i++;
						}
						if ((infx<ROW&&infx>-1)&&(infy<COLUMN&&infy>-1))
						{
							affect_animal(infx, infy);
						}
						
					} while (count < 9 && cell_count < (cell+1));
					cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				
				
			break;
			case 2:
			do{
				cout << "Write the row that you want to start the fishing net> ";
				cin >> r;
				if (r>ROW || r<0)
				{
					cout <<"\n"<<r<< " is invalid value for row!!!\n The correct values is between "<<ROW<< "and 0"<<endl;
				}
			}while(r>ROW || r<0);
			do{
				cout << "Write the column that you want to start the fishing net> "; 
				cin >> c;
				if (c>COLUMN || c<0)
				{
					cout <<"\n"<<c<< " is invalid value for column!!!\n The correct values is between "<<COLUMN<< "and 0"<<endl;
				}
			}while(c>COLUMN || c<0);
			do{
				cout <<"Give me the size of fishing net.(How many cell affects)> ";
				cin >> net;
				if (net>40 || net<1)
				{
					cout <<"\n"<<net<< " is invalid value for cells!!!\n The correct values is between 40 and 1"<<endl;
				}
			}while(net>40 || net<1);
					j = 1;
					count_2 = 1;
					cout <<"~~~~~~~~Fish in the net~~~~~~~~"<<endl;
					fishing(r, c);
						do
						{
							switch(count){
								case 1:
								netx = r-j;
								nety = c-j;
								break;
								case 2:
								netx = r-j;
								nety = c;
								break;
								case 3:
								netx = r-j;
								nety = c+j;
								break;
								case 4:
								netx = r;
								nety = c-j;
								break;
								case 5:
								netx = r;
								nety = c+j;
								break;
								case 6:
								netx = r+j;
								nety = c-j;
								break;
								case 7:
								netx = r+j;
								nety = c;
								break;
								case 8:
								netx = r+j;
								nety = c+j;
								break;

							}
							count_2++;
							net_count++;
							if(count_2>8 && net_count < (net+1)){
								count_2 = 1;
								j++;
							}
							if ((netx<ROW&&netx>-1)&&(nety<COLUMN&&nety>-1))
							{
								fishing(netx, nety);
							}
							
						} while (count_2 < 9 && net_count < (net+1));
					
					cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			break;		
	}
}
//Function affect animal from infection
void affect_animal(int infx, int infy){
	if (map[infx][infy] != 0)
	{
		if (map[infx][infy]->getCategory() == "Plantplakton")
		{
			map[infx][infy] = 0;
		}else if (map[infx][infy]->getCategory() == "Animalplakton")
		{
			death(infx, infy);
			map[infx][infy] = 0;
		}else{
			if (map[infx][infy]->getsize()>=2)
			{
				cout <<"Sick: "<<map[infx][infy]->getname()<<"("<<map[infx][infy]->getx()<<", "<<map[infx][infy]->gety()<<")"<<endl;
				map[infx][infy]->setsize((map[infx][infy]->getsize()/2));
			}else{
				cout <<"Dead: "<<map[infx][infy]->getname()<<"("<<map[infx][infy]->getx()<<", "<<map[infx][infy]->gety()<<")"<<endl;;
				death(infx, infy);
				map[infx][infy] = 0;
			}
		}
	}
}

//Function affect animal from net.
void fishing(int netx, int nety){
	int posib;
	if (map[netx][nety] != 0)
	{
		if (map[netx][nety]->getCategory() != "Plantplakton")
		{
			if (map[netx][nety]->getCategory() == "Animalplakton")
			{
				posib = 1+rand()%4;
				if (posib<5 && posib>1)
				{
					cout <<map[netx][nety]->getname()<<"("<<map[netx][nety]->getx()<<", "<<map[netx][nety]->gety()<<")"<<endl;
					death(netx, nety);
					map[netx][nety] = 0;
				}
			}else if (map[netx][nety]->getCategory() == "Shellfish" || map[netx][nety]->getCategory() == "Arthropod" || map[netx][nety]->getCategory() == "Mollusca" || map[netx][nety]->getCategory() == "Smallfish")
			{
				posib = 1+rand()%4;
				if (posib<4 && posib>1)
				{
					cout <<map[netx][nety]->getname()<<"("<<map[netx][nety]->getx()<<", "<<map[netx][nety]->gety()<<")"<<endl;
					death(netx, nety);
					map[netx][nety] = 0;
				}
			}else{
				posib = 1+rand()%4;
				if (posib<3 && posib>1)
				{
					cout <<map[netx][nety]->getname()<<"("<<map[netx][nety]->getx()<<", "<<map[netx][nety]->gety()<<")"<<endl;
					death(netx, nety);
					map[netx][nety] = 0;
				}
			}
		}
	}
}
