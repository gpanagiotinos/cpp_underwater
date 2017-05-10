#define ROW 10
#define COLUMN 100
Animal *map[ROW][COLUMN];
//Αριθμός ζώον ανα κατηγορία για την αρχίκη κατάσταση του πίνακα.
#define MAMMAL 8
#define	FISH 8
#define SEAREPTILE 8
#define SMALLFISH 20
#define MOLLUSCA 20
#define ARTHROPOD 20
#define SHELLFISH 20
#define PLANTPLAKTON 10
#define ANIMALPLAKTON 40

#define CATEGORY 9

#define POSITION 8
int pos_table[POSITION][2];
//Πίνακας για τους θανάτους ανα οργανισμό.
int dead_table[CATEGORY-1] = {0};
//Πίνακας για την μέση κατνάλωση τροφής την τελευταία εβδομάδα.
int wfood[CATEGORY-1] = {0};



string categories[CATEGORY] = {"Plantplakton", "Animalplakton", "Shellfish", "Arthropod", "Mollusca", "Smallfish","Seareptile", "Fish", "Mammal"};
string food_cat[CATEGORY-1][5] = {/*animalplakton*/{"Plantplakton"}, /*shellfish*/{"Plantplakton", "Animalplakton"}, /*arthropod*/{"Plantplakton", "Animalplakton", "Shellfish", "Smallfish"}, /*mollusca*/{"Plantplakton", "Animalplakton", "Shellfish", "Smallfish"}, /*smallfish*/{"Plantplakton", "Animalplakton", "Shellfish"}, /*seareptile*/{"Arthropod", "Mollusca", "Smallfish"}, /*fish*/{"Arthropod", "Mollusca","Shellfish", "Smallfish"}, /*mammal*/{"Arthropod", "Mollusca", "Smallfish", "Seareptile", "Fish"}};
#define SYMBOLS 9 //Σύμβολα ανα κατηγορία.
string symbol[SYMBOLS] = {"p", "a", "@", "&", "{", "^","$", "#", "!"};


//Πίνακες ανα κατηγορία θαλάσσιων οργανισμών, με τα ονόματα το θαλάσσιων οργανισμών.
#define PP_SIZE 2 
string plantplakton[PP_SIZE] = {"seaweed", "coral"};
double def_pp[PP_SIZE][3] = {{0, 1.0, 0.2}, {0, 1.0, 0.4}};


//Nonplakton Constructor Init variables (_age, _size, _grow, _food_to_grow, _weekfood, _dayfood, _moves)
#define AP_SIZE 2
#define AP_FOOD 1
string animalplakton[AP_SIZE] = {"ap_a","ap_b"};
double def_ap[AP_SIZE][7] = {{0,2.0,3.0,0.5,0.0,0.0,3}, {0,2.0,3.0,0.5,0.0,0.0,3}};

#define SF_SIZE 2
string shellfish[SF_SIZE] = {"mussel", "oyster"};
double def_sf[SF_SIZE][7] = {{0,2.0,3.0,0.5,0.0,0.0,1}, {0,2.0,3.0,0.5,0.0,0.0,1}};

#define AR_SIZE 2
string arthropod[AR_SIZE] = {"lobster", "scampi"};
double def_ar[AR_SIZE][7] = {{0,2.0,3.0,0.5,0.0,0.0,3}, {0,2.0,3.0,0.5,0.0,0.0,3}};

#define MO_SIZE 2
string mollusca[MO_SIZE] = {"octopus","cuttlefish"};
double def_mo[MO_SIZE][7] = {{0,2.0,3.0,1.0,0.0,0.0,5}, {0,2.0,3.0,1.0,0.0,0.0,5}};

#define SMF_SIZE 3
string smallfish[SMF_SIZE] = {"sardine","hornbeam","fry"};
double def_smf[SMF_SIZE][7] = {{0,2.0,3.0,1.0,0.0,0.0,5}, {0,2.0,3.0,1.0,0.0,0.0,5}, {0,2.0,3.0,1.0,0.0,0.0,5}};

#define SR_SIZE 2
string seareptile[SR_SIZE] = {"seaturtle", "eel"};
double def_sr[SR_SIZE][7] = {{0,1.0,2.0,2.0,0.0,0.0,5}, {0,1.0,2.0,2.0,0.0,0.0,5}};

#define F_SIZE 2
string fish[F_SIZE] = {"haddock", "tone"};
double def_f[F_SIZE][7] = {{0,1.0,2.0,2.0,0.0,0.0,7}, {0,1.0,2.0,2.0,0.0,0.0,8}};

#define MA_SIZE 4
string mammal[MA_SIZE] = {"wale", "shark", "dolphin", "seal"};
double def_ma[MA_SIZE][7] = {{0,1.0,2.0,2.0,0.0,0.0,10}, {0,1.0,2.0,2.0,0.0,0.0,10}, {0,2.0,2.0,2.0,0.0,0.0,10}, {0,1.0,2.0,2.0,0.0,0.0,10}};

#define START_MENU 8
string start_menu[START_MENU] = {"Start","Resume", "Restart", "Insert", "Category_Info", "Animal_Info", "Foreign_Factors", "Exit"};
//Category Info, Avg = Average
#define CAT_INFO 5
string cat_info[CAT_INFO] = {"Avg_size", "Population", "Avg_consumption", "Mortality_rate", "Avg_age"};
//Table for foreign factors
#define FOR_FAC 2
string foreign_factors[FOR_FAC] = {"Infection", "Nets"};






//functions
void init_map();
void default_input();
void print(string [], int);
int check(string, string [], int);
int check_position(int, int);
void create(int, int);
void fill_area(int, int, int);
void print_map();
int find_symbol(int, int);
void grow();
void rand_position(int &, int &);
void print_info();
void print_exit_msg();
void operation();
int choose_move(int, int, int, int);
int eat(int, int, int, int);
void rand_move(int &, int &);
int multiplication(int , int , int , int);
void new_animal(int , int , int , int);
void init_moves();
void death(int, int);
void fun_wfood();
bool iskeypressed(unsigned);
void print_cat_info(int, int);
void print_animal_info();
void affect_map(int);
void affect_animal(int, int);
void fishing(int, int);