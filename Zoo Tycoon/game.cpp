/*Program Filename: game.cpp
 * Author:Dennis
 * Date:2/20/17
 * Description: file contains the method definitions for class game
 * Input:none
 * Output:none
 */
#include<iostream>
#include<cstdlib>

#include"animal.hpp"
#include"monkey.hpp"
#include"sloth.hpp"
#include"sea_otter.hpp"
#include"game.hpp"

using namespace std;
/*Function: Game
 * Description: Default constructor for class Game
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: reates array for animals, presets money to 100000, and sets day to 0.
 */
Game::Game(){
	days = 0;
	money = 100000;
	daily_food_cost = 50;
	bankrupt = false;

	num_monkeys=0;
	total_monkeys = new Monkey[num_monkeys];
	num_sloths=0;
	total_sloths = new Sloth[num_sloths];
	num_sea_otters=0;
	total_sea_otters = new Sea_otter[num_sea_otters];
}
/*Function: ~Game
 * Description: Default destructor for class animal
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: frees arrays for animals
 */
Game::~Game(){
	cout<<"in game destructor!"<<endl;	
	delete [] total_monkeys;
	delete [] total_sloths;
	delete [] total_sea_otters;
}
/*Function: get days
 * Description: returns days in the game
 * Parameters: none
 * Pre-conditions: none 
 * Post-conditions: integer days
 */
int & Game::get_days(){
	return days;
}
/*Function: get money
 * Description: returns user money
 * Parameters: none
 * Pre-conditions: none 
 * Post-conditions: integer age of money
 */
float &Game::get_money(){
	return money;
}
/*Function: get daily food cost
 * Description: returns daily good cost
 * Parameters: none
 * Pre-conditions: none 
 * Post-conditions: integer of daily food cost
 */
float Game::get_daily_food_cost(){
	return daily_food_cost;
}
/*Function: get bankrupt
 * Description: returns if the user is bankrupt or not
 * Parameters: none
 * Pre-conditions: none 
 * Post-conditions: boolean for bankrupt if true or false
 */
bool Game::get_bankrupt(){
	return bankrupt;
}
/*Function: set bankrupt
 * Description: set bankruptcy
 * Parameters: bool 
 * Pre-conditions: True or false if bankrupt
 * Post-conditions: bool is set to true or false
 */
void Game::set_bankrupt(bool x){
	if (x==false){
		bankrupt = false;
	}
	if (x==true){
		bankrupt = true;
	}
}










/*Function: get specific monkey
 * Description: selects a specific monkey in the array
 * Parameters: int
 * Pre-conditions: int for specific monkey
 * Post-conditions: returns address of specific monkey
 */
Monkey & Game::get_specific_monkey(int x){ //THIS IS IMPORTANT WHEN YOU GO A LEVEL UP ONE, SUCH AS GOING INTO MAIN (SAME WITH ALL GET FUNCTIONS)
	return total_monkeys[x];

}

/*Function: add monkey
 * Description: adds a monkey onto the array 
 * Parameters: nont
 * Pre-conditions: none
 * Post-conditions: a new monkey is added to array 
 */
void Game::add_monkey(){
	Monkey temp_array[num_monkeys];
	for(int i = 0; i< num_monkeys;i++){
		temp_array[i]=total_monkeys[i];
	}
	num_monkeys= num_monkeys+1;
	delete [] total_monkeys;//Deletes old array with one slotj
	total_monkeys = new Monkey[num_monkeys];//Should create 2 slotjs now

	for(int i=0;i<num_monkeys-1;i++){//For loop is to assign num_monkeys-1 because it added a spot
		total_monkeys[i].set_age(temp_array[i].get_age());
		total_monkeys[i].set_cost(temp_array[i].get_cost());
		total_monkeys[i].set_babies(temp_array[i].get_babies());
		total_monkeys[i].set_food_cost(temp_array[i].get_food_cost());
		total_monkeys[i].set_revenue(temp_array[i].get_revenue());
	}		
}
/*Function: remove monkey 
 * Description: remove a monkey onto the array 
 * Parameters: int
 * Pre-conditions: int for specific monkey
 * Post-conditions: a monkey is deleted from the array 
 */
void Game::remove_monkey(int removed){
	Monkey temp_array[num_monkeys];
	for(int i = 0; i< removed;i++){ //All monkeys up to removed are transfered to temporary array
		temp_array[i]=total_monkeys[i];
	}
	for(int i = removed+1; i<num_monkeys;i++){//All monkeys after removed are transfered to temporary array 
		temp_array[i-1]=total_monkeys[i];
	}
	num_monkeys--; //Change array size
	delete [] total_monkeys;//Deletes old array with one monkey
	total_monkeys = new Monkey[num_monkeys];//Should create array size of 1 less
	cout<<num_monkeys<<endl;
	for(int i=0;i<num_monkeys;i++){//For loop is to copy old one
		total_monkeys[i].set_age(temp_array[i].get_age());
		total_monkeys[i].set_babies(temp_array[i].get_babies());
		total_monkeys[i].set_cost(temp_array[i].get_cost());
		total_monkeys[i].set_food_cost(temp_array[i].get_food_cost());
		total_monkeys[i].set_revenue(temp_array[i].get_revenue());
	}

}

/*Function: display monkey
 * Description: runs through array and displays information about the monkeys 
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none 
 */
void Game::display_monkeys(){
	for(int i=0; i<num_monkeys;i++){
		cout<<"Monkey "<<i+1<<endl;
		cout<<"Age: "<<(total_monkeys[i]).get_age()<<endl;
		cout<<"Cost: "<<(total_monkeys[i]).get_cost()<<endl;
		cout<<"Babies: "<<(total_monkeys[i]).get_babies()<<endl;
		cout<<"Food Cost: "<<(total_monkeys[i]).get_food_cost()<<endl;
		cout<<"Revenue: "<<(total_monkeys[i]).get_revenue()<<endl;
		cout<<endl;
	}
	cout<<endl;
}

/*Function: get num monkeys
 * Description: returns the number of monkeys
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: int for number of monkeys
 */
int Game::get_num_monkeys(){
	return num_monkeys;

}




/*Function: get specific sloth
 * Description: selects a specific sloth in the array
 * Parameters: int
 * Pre-conditions: int for specific sloth
 * Post-conditions: returns address of specific sloth
 */
Sloth & Game::get_specific_sloth(int x){ //THIS IS IMPORTANT WHEN YOU GO A LEVEL UP ONE, SUCH AS GOING INTO MAIN (SAME WITH ALL GET FUNCTIONS)
	return total_sloths[x];	

}

/*Function: add sloth
 * Description: adds a sloth onto the array 
 * Parameters: nont
 * Pre-conditions: none
 * Post-conditions: a new sloth is added to array 
 */
void Game::add_sloth(){
	Sloth temp_array[num_sloths];
	for(int i = 0; i< num_sloths;i++){
		temp_array[i]=total_sloths[i];
	}
	num_sloths++;
	delete [] total_sloths;//Deletes old array with one slotj
	total_sloths = new Sloth[num_sloths];//Should create 2 slotjs now

	for(int i=0;i<num_sloths-1;i++){//For loop is to assign num_sloths-1 because it added a spot
		total_sloths[i].set_age(temp_array[i].get_age());
		total_sloths[i].set_cost(temp_array[i].get_cost());
		total_sloths[i].set_babies(temp_array[i].get_babies());
		total_sloths[i].set_food_cost(temp_array[i].get_food_cost());
		total_sloths[i].set_revenue(temp_array[i].get_revenue());
	}		
}
/*Function: remove sloth 
 * Description: remove a sloth onto the array 
 * Parameters: int
 * Pre-conditions: int for specific sloth
 * Post-conditions: a sloth is deleted from the array 
 */
void Game::remove_sloth(int removed){
	Sloth temp_array[num_sloths];
	for(int i = 0; i< removed;i++){ //All sloths up to removed are transfered to temporary array
		temp_array[i]=total_sloths[i];
	}
	for(int i = removed+1; i<num_sloths;i++){//All sloths after removed are transfered to temporary array 
		temp_array[i-1]=total_sloths[i];
	}
	num_sloths--; //Change array size
	delete [] total_sloths;//Deletes old array with one sloth
	total_sloths = new Sloth [num_sloths];//Should create array size of 1 less
	cout<<num_sloths<<endl;
	for(int i=0;i<num_sloths;i++){//For loop is to copy old one
		total_sloths[i].set_age(temp_array[i].get_age());
		total_sloths[i].set_babies(temp_array[i].get_babies());
		total_sloths[i].set_cost(temp_array[i].get_cost());
		total_sloths[i].set_food_cost(temp_array[i].get_food_cost());
		total_sloths[i].set_revenue(temp_array[i].get_revenue());
	}

}

/*Function: display sloth
 * Description: runs through array and displays information about the sloths 
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none 
 */
void Game::display_sloths(){
	for(int i=0; i<num_sloths;i++){
		cout<<"Sloth "<<i+1<<endl;
		cout<<"Age: "<<(total_sloths[i]).get_age()<<endl;
		cout<<"Cost: "<<(total_sloths[i]).get_cost()<<endl;
		cout<<"Babies: "<<(total_sloths[i]).get_babies()<<endl;
		cout<<"Food Cost: "<<(total_sloths[i]).get_food_cost()<<endl;
		cout<<"Revenue: "<<(total_sloths[i]).get_revenue()<<endl;
		cout<<endl;
	}
	cout<<endl;
}
/*Function: get num sloths
 * Description: returns the number of sloths
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: int for number of sloths
 */
int Game::get_num_sloths(){
	return num_sloths;

}




/*Function: get specific sea otter
 * Description: selects a specific sea otter in the array
 * Parameters: int
 * Pre-conditions: int for specific sea otter
 * Post-conditions: returns address of specific sea otter
 */
Sea_otter & Game::get_specific_sea_otter(int x){ //THIS IS IMPORTANT WHEN YOU GO A LEVEL UP ONE, SUCH AS GOING INTO MAIN (SAME WITH ALL GET FUNCTIONS)
	return total_sea_otters[x];
}
/*Function: add sea otter
 * Description: adds a sea otter onto the array 
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: a new sea otter is added to array 
 */
void Game::add_sea_otter(){
	Sea_otter temp_array[num_sea_otters];
	for(int i = 0; i< num_sea_otters;i++){
		temp_array[i]=total_sea_otters[i];
	}
	num_sea_otters++;
	delete [] total_sea_otters;//Deletes old array with one slotj
	total_sea_otters = new Sea_otter[num_sea_otters];//Should create 2 slotjs now

	for(int i=0;i<num_sea_otters-1;i++){//For loop is to assign num_sea_otterss-1 because it added a spot
		total_sea_otters[i].set_age(temp_array[i].get_age());
		total_sea_otters[i].set_cost(temp_array[i].get_cost());
		total_sea_otters[i].set_babies(temp_array[i].get_babies());
		total_sea_otters[i].set_food_cost(temp_array[i].get_food_cost());
		total_sea_otters[i].set_revenue(temp_array[i].get_revenue());
	}		
}
/*Function: remove sea otter
 * Description: remove a sea otter onto the array 
 * Parameters: int
 * Pre-conditions: int for specific sea otter
 * Post-conditions: a sea otter is deleted from the array 
 */
void Game::remove_sea_otter(int removed){
	Sea_otter temp_array[num_sea_otters];
	for(int i = 0; i< removed;i++){ //All sea_otters up to removed are transfered to temporary array
		temp_array[i]=total_sea_otters[i];
	}
	for(int i = removed+1; i<num_sea_otters;i++){//All sea otters after removed are transfered to temporary array 
		temp_array[i-1]=total_sea_otters[i];
	}
	num_sea_otters--; //Change array size
	delete [] total_sea_otters;//Deletes old array with one sea otter
	total_sea_otters = new Sea_otter [num_sea_otters];//Should create array size of 1 less
	cout<<num_sea_otters<<endl;
	for(int i=0;i<num_sea_otters;i++){//For loop is to copy old one
		total_sea_otters[i].set_age(temp_array[i].get_age());
		total_sea_otters[i].set_babies(temp_array[i].get_babies());
		total_sea_otters[i].set_cost(temp_array[i].get_cost());
		total_sea_otters[i].set_food_cost(temp_array[i].get_food_cost());
		total_sea_otters[i].set_revenue(temp_array[i].get_revenue());
	}

}

/*Function: display sea otter
 * Description: runs through array and displays information about the sea otters 
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none 
 */
void Game::display_sea_otters(){
	for(int i=0; i<num_sea_otters;i++){
		cout<<"Sea_otter "<<i+1<<endl;
		cout<<"Age: "<<(total_sea_otters[i]).get_age()<<endl;
		cout<<"Cost: "<<(total_sea_otters[i]).get_cost()<<endl;
		cout<<"Babies: "<<(total_sea_otters[i]).get_babies()<<endl;
		cout<<"Food Cost: "<<(total_sea_otters[i]).get_food_cost()<<endl;
		cout<<"Revenue: "<<(total_sea_otters[i]).get_revenue()<<endl;
		cout<<endl;
	}
	cout<<endl;
}
/*Function: get num sea otters
 * Description: returns the number of sea otters
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: int for number of sea otters
 */
int Game::get_num_sea_otters(){
	return num_sea_otters;

}





/*Function: subtract food cost 
 * Description: displays information about the cost of food per animal species and removes cost from money
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: money-food cost
 */
void Game::subtract_food_cost(){
	float base_percent;
	float monkey_cost;
	float sloth_cost;
	float sea_otter_cost;
	srand(time(NULL));
	base_percent = (float)((rand()%51)+75)/(float)100; //Gives percentage for food cost 75-125
	daily_food_cost = daily_food_cost * base_percent; //gives daily food cost from 50 dollars
	cout<<"Base Food Cost: "<<daily_food_cost<<endl;

	monkey_cost = ((daily_food_cost*total_monkeys[0].get_food_cost())*num_monkeys);  //Food cost per monkey * number of monkeys
	sloth_cost = ((daily_food_cost*total_sloths[0].get_food_cost())*num_sloths); 
	sea_otter_cost = ((daily_food_cost*total_sea_otters[0].get_food_cost())*num_sea_otters);

	cout<<"Overall Monkey Food Cost: "<< monkey_cost<<endl;	
	cout<<"Overall Sloth Food Cost: "<< sloth_cost<<endl;	
	cout<<"Overall Sea Otter Food Cost: "<<	sea_otter_cost<<endl;
	cout<<"Overall Food Cost: "<<monkey_cost+sloth_cost+sea_otter_cost<<endl;

	money= money-(monkey_cost+sloth_cost+sea_otter_cost); //Subtract from money 
}
/*Function: recieve revenue 
 * Description: displays information about the revenue per animal species and adds profit to money
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: money + revenue
 */
void Game::recieve_revenue(int bonus){
		int monkey_revenue;
		int sloth_revenue;
		int sea_otter_revenue;
		int monkey_bonus;
		srand(time(NULL));

	if(bonus==1){
		monkey_revenue = ((total_monkeys[0].get_revenue())*num_monkeys);  //Food cost per monkey * number of monkeys
		sloth_revenue = ((total_sloths[0].get_revenue())*num_sloths); 
		sea_otter_revenue = ((total_sea_otters[0].get_revenue())*num_sea_otters);
		cout<<"Overall Monkey Revenue: "<< monkey_revenue<<endl;	
		cout<<"Overall Sloth Revenue: "<< sloth_revenue<<endl;	
		cout<<"Overall Sea Otter Revenue: "<<sea_otter_revenue<<endl;
		cout<<"Overall Revenue: "<<monkey_revenue+sloth_revenue+sea_otter_revenue<<endl;
		money = money + (monkey_revenue+sloth_revenue+sea_otter_revenue);
	}
	else if(bonus==2){//BONUS for monkeys
		monkey_revenue = ((total_monkeys[0].get_revenue())*num_monkeys);  //Food cost per monkey * number of monkeys
		sloth_revenue = ((total_sloths[0].get_revenue())*num_sloths); 
		sea_otter_revenue = ((total_sea_otters[0].get_revenue())*num_sea_otters);
		monkey_bonus = ((rand()%250)+250);

		cout<<"Overall Monkey Revenue: "<< monkey_revenue<<endl;
		cout<<"Bonus Monkey Revenue: "<<monkey_bonus<<endl;	
		cout<<"Overall Sloth Revenue: "<< sloth_revenue<<endl;	
		cout<<"Overall Sea Otter Revenue: "<<sea_otter_revenue<<endl;
		cout<<"Overall Revenue: "<<monkey_revenue+sloth_revenue+sea_otter_revenue+monkey_bonus<<endl;
		money = money + (monkey_revenue+sloth_revenue+sea_otter_revenue+monkey_bonus);


	}
}
/*Function: increment day
 * Description: the number of days is incremented along with the age of the animals
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: days +1, and age+1 for all animals
 */
void Game::increment_day(){
	days++;
	for(int i=0;i<num_monkeys;i++){
		total_monkeys[i].set_age(total_monkeys[i].get_age()+1);
	}
	for(int i=0;i<num_sloths;i++){
		total_sloths[i].set_age(total_sloths[i].get_age()+1);
	}
	for(int i=0;i<num_sea_otters;i++){
		total_sea_otters[i].set_age(total_sea_otters[i].get_age()+1);
	}
}

