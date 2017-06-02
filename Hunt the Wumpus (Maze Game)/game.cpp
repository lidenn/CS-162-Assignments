/********
 * Program Filename: Game.cpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the game class functions for hunt the wumpus
 * Input: None
 * Output: None
 */
#include<vector>
#include<iostream>
#include<cstdlib>
#include<string>

#include"room.hpp"
#include"event.hpp"
#include"wumpus.hpp"
#include"game.hpp"
using namespace std;

/*Function: Game 
 * Description: Class constructor for game
 * Parameters: Int
 * Pre-conditions: Size of board must be provided
 * Post-conditions: Creates a 2d vector based on size of board
 */
Game::Game(int size):cave_size(size){
	srand(time(NULL));  
	for (int r = 0; r < cave_size; r++) {  //SETS BOARD DYNAMICALLY
		vector<Room*> row;
		for (int c = 0; c < cave_size; c++) {
			row.push_back(new Room);
		}
		cave.push_back(row);
	}	

}




/*Function: Print nearby event
 * Description: Prints nearby events on the array
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions: displays nearby events
 */
void Game::print_nearby_event(){ //Right now it will print any event at [0][0] depending on the pointer
	if(user_y+1<cave_size&&cave[user_y+1][user_x]->get_event_num()>1){ //Checks if it is in range of the baord and then if it actually contains an event
		cout<<cave[user_y+1][user_x]->get_event_warning()<<endl;
	}
	if(user_x+1<cave_size&&cave[user_y][user_x+1]->get_event_num()>1){
		cout<<cave[user_y][user_x+1]->get_event_warning()<<endl;
	}
	if(user_x-1>=0&&cave[user_y][user_x-1]->get_event_num()>1){
		cout<<cave[user_y][user_x-1]->get_event_warning()<<endl;
	}
	if(user_y-1>=0&&cave[user_y-1][user_x]->get_event_num()>1){
		cout<<cave[user_y-1][user_x]->get_event_warning()<<endl;
	}

}
/*Function: Print board
 * Description: Prints the board (for the grader, backend)
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions: displays board with certain events
 */

void Game::print_board(){
	for (int r = 0; r < cave_size; r++) {
		for (int c = 0; c < cave_size; c++) {
			cout<<cave[r][c]->get_event_num()<< " | ";

		}
		cout<<endl;
	}
}
/*Function: Set board
 * Description: Set the board by filling each room pointer with a type of event
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions: Sets board
 */
void Game::set_board(){ //Sets board event number then assign event number with an event
	int rand_x;
	int rand_y;
	for(int n = 1; n<4; n++){  //Sets the rope, wumpus, gold
		bool placed = false;
		while (placed == false){  //Goes to next number once it is placed, or true
			rand_x = rand()%cave_size;
			rand_y = rand()%cave_size;
			if (cave[rand_y][rand_x]->get_event_num() ==0){
				cave[rand_y][rand_x]->set_event_num(n);
				placed = true;
			}
		}
	}
	for (int n=0; n<2; n++){ //Sets the two bottomless
		int placed = false;
		while (placed == false){  //Goes to next number once it is placed, or true
			rand_x = rand()%cave_size;
			rand_y = rand()%cave_size;
			if (cave[rand_y][rand_x]->get_event_num() ==0){
				cave[rand_y][rand_x]->set_event_num(4);
				placed = true;
			}
		}
	}
	for (int n=0; n<2; n++){ //Sets the two bats
		int placed = false;
		while (placed == false){  //Goes to next number once it is placed, or true
			rand_x = rand()%cave_size;
			rand_y = rand()%cave_size;
			cout<<endl;
			if (cave[rand_y][rand_x]->get_event_num() ==0){
				cave[rand_y][rand_x]->set_event_num(5);
				placed = true;
			}
		}
	}
	for(int r =0; r<cave_size; r++){  //This will set the adventure starting location at 1
		for(int c=0; c<cave_size; c++){
			if(cave[r][c]->get_event_num() ==1){ //Rope
				start_user_x = c; //Sets the initial x and y values of the adventurer
				start_user_y = r;					
				user_x = c;
				user_y = r;
				cave[user_y][user_x]->set_adventurer(true); //Displays on user board

			}			
			else if(cave[r][c]->get_event_num() ==2){ //All of these sets the eptr in room for polymorphism //Wumpus
				cave[r][c]->set_event(2);
				wumpus_y = r;
				wumpus_x = c;
				start_wumpus_y = r;
				start_wumpus_x = c;
			}			
			else if(cave[r][c]->get_event_num() ==3){ //Gold
				cave[r][c]->set_event(3);
			}		
			else if(cave[r][c]->get_event_num() ==4){ //Pit
				cave[r][c]->set_event(4);
			}	
			else if(cave[r][c]->get_event_num() ==5){ //Bat
				cave[r][c]->set_event(5);
			}
			else{
				cave[r][c]->set_event(0); //Empty
			}
		}
	}
}

/*Function: Print adventurer board
 * Description: Prints the board (for the player)
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions: displays board with caves, X marks the user location
 */
void Game::print_adventurer_board(){
	for (int r = 0; r < cave_size; r++) {
		for (int c = 0; c < cave_size; c++) {
			if(cave[r][c]->get_adventurer() == 0){
				cout<<" ";
			}
			else if(cave[r][c]->get_adventurer() == 1){
				cout<<"X";
			}
			cout<<" | ";
			//cout<<cave[r][c]->get_adventurer()<< " | ";

		}
		cout<<endl;
	}		

}	

/*Function: Move adventurer
 * Description:Moves the adventurer north, south, west or east
 * Parameters: int
 * Pre-conditions:int for direction
 * Post-conditions:Moves the user coordinates depending on input, also changes the adventurer board
 */
void Game::move_adventurer(int direction){  //Function moves user_x and user_y, but displayed through set adventurer
	if(direction==1 && (user_y-1)>=0){ //NORTH	
		cave[user_y][user_x]->set_adventurer(false);	
		user_y=user_y-1;
		cave[user_y][user_x]->set_adventurer(true);	
	}
	else if(direction==2 && (user_y+1)<cave_size){ //SOUTH
		cave[user_y][user_x]->set_adventurer(false);	
		user_y=user_y+1;
		cave[user_y][user_x]->set_adventurer(true);	
	}
	else if(direction==3 && (user_x-1)>=0){ //WEST
		cave[user_y][user_x]->set_adventurer(false);	
		user_x=user_x-1;
		cave[user_y][user_x]->set_adventurer(true);	
	}			
	else if(direction==4 && (user_x+1)<cave_size){ //EAST
		cave[user_y][user_x]->set_adventurer(false);	
		user_x=user_x+1;
		cave[user_y][user_x]->set_adventurer(true);	
	}

	else{
		cout<<"out of range"<<endl;
	}

}

/*Function: Shoot Arrow
 * Description:Shoot arrow north, south, west or east, used to kill wumpus
 * Parameters: int
 * Pre-conditions:int for direction
 * Post-conditions: Shoots the arrow, 3 caves away in certain direction 
 */
void Game::shoot_arrow(int direction){
	srand(time(NULL));
	arrow_x = user_x;
	arrow_y = user_y;
	for(int n=0; n<3; n++){
		if(direction==1 && (arrow_y-1)>=0 && wumpus == false){ //NORTH	
			cout<<"Shoot north"<<endl;
			arrow_y=arrow_y-1;

		}
		else if(direction==2 && (arrow_y+1)<cave_size&& wumpus == false){ //SOUTH
			cout<<"Shoot south"<<endl;
			arrow_y=arrow_y+1;				
		}
		else if(direction==3 && (arrow_x-1)>=0&& wumpus == false){ //WEST
			cout<<"Shoot west"<<endl;
			arrow_x=arrow_x-1;				
		}			
		else if(direction==4 && (arrow_x+1)<cave_size&& wumpus == false){ //EAST
			cout<<"Shoot east"<<endl;
			arrow_x=arrow_x+1;

		}	
		else{
			cout<<"Arrow hit a wall"<<endl;
			break;
		}
		if (arrow_y == wumpus_y && arrow_x == wumpus_x){
			cout<<"You killed the Wumpus"<<endl;
			cave[wumpus_y][wumpus_x]->delete_event(); //Deletes old wumpus
			cave[wumpus_y][wumpus_x]->set_event_num(0); //Set the number =0 or it will segfault because calls are based off of set nums
			wumpus = true;
			return;
		}	
	}
	cout<<"Arrow didn't hit anything"<<endl;
	arrows= arrows-1;
	cout<<"Arrows left: "<<arrows<<endl;

	if(wumpus == false){
		bool wumpus_set;
		cave[wumpus_y][wumpus_x]->delete_event(); //Deletes old wumpus
		cave[wumpus_y][wumpus_x]->set_event_num(0); //Set the number =0 or it will segfault because calls are based off of set nums
		while (wumpus_set ==false){
			wumpus_x = rand()%cave_size;
			wumpus_y = rand()%cave_size;
			if(cave[wumpus_y][wumpus_x]->get_event_num()==0){
				cave[wumpus_y][wumpus_x]->set_event(2); //sets the class as wumpus using polymorphism
				cave[wumpus_y][wumpus_x]->set_event_num(2); //Set the number as 2 for new wumpus
				wumpus_set = true;
			}
		}	

	}
}
/*Function: Run event
 * Description:depending on user location, it will run the event coordinated with the event number
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: Based on options, you either die, find gold, get moved, or nothing happens
 */
void Game::run_event(){ //Meant for pit and wumpus
	srand(time(NULL));

	if (cave[user_y][user_x]->get_event_num() == 1){
		cout<<"You are at the rope"<<endl;
		if(gold == true && wumpus == true){		
			win = true; //make false but game is actually over
			cout<<"WINNER"<<endl;
		}

	}
	else if (cave[user_y][user_x]->get_event_num() == 2){
		cout<<"You've ran into the wumpus!"<<endl;		
		is_alive = false;
		return;
	}
	else if (cave[user_y][user_x]->get_event_num() == 3){
		cout<<"You've found the gold!"<<endl;		
		gold = true;
		return;
	}
	else if (cave[user_y][user_x]->get_event_num() == 4){
		cout<<"You've fallen into a pit!"<<endl;			
		is_alive = false;
		return;
	}
	else if (cave[user_y][user_x]->get_event_num() == 5){
		cave[user_y][user_x]->set_adventurer(false);	
		cout<<"You've been carried away by super bats!"<<endl;		
		int num1 = rand()%cave_size;
		int num2 = rand()%cave_size;
		user_x = num1;
		user_y = num2;
		cave[user_y][user_x]->set_adventurer(true);	
		return;
	}


}

/*Function: Run event
 * Description:used to check if you are still alive or not
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: true if you are still alive, false if youre dead
 */

bool Game::check_is_alive(){ //functions checks if you are dead and changes is dead, important before  you move (if you get displaced)
	if (arrows<=0){    //Check if you're dead first
		cout<<"You've run out of arrows! "<<endl;
		is_alive = false;
		return false;
	}

	if (cave[user_y][user_x]->get_event_num() == 1){
		if(gold == true && wumpus == true){		
			win = true; //make false but game is actually over
			cout<<"WINNER"<<endl;
			return false;
		}
	}
	else if (cave[user_y][user_x]->get_event_num() == 2){
		cout<<"You've ran into the wumpus!"<<endl;		
		is_alive = false;
		return false;
	}
	else if (cave[user_y][user_x]->get_event_num() == 3){
		cout<<"You've found the gold!"<<endl;		
		gold = true;
		return true;
	}
	else if (cave[user_y][user_x]->get_event_num() == 4){
		cout<<"You've fallen into a pit!"<<endl;			
		is_alive = false;
		return false;
	}
	return true;
}
/*Function: Game reset
 * Description:used to reset the game for same board
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: New game with same board
 */
void Game::game_reset(){
	cave[user_y][user_x]->set_adventurer(false);
	user_x = start_user_x;
	user_y = start_user_y;
	cave[user_y][user_x]->set_adventurer(true); //Reset the starting point
	if (wumpus==false){
		cave[wumpus_y][wumpus_x]->delete_event(); //Deletes old wumpus
		cave[wumpus_y][wumpus_x]->set_event_num(0); //Set the number =0 or it will segfault because calls are based off of set nums
	}
	wumpus_x = start_wumpus_x;
	wumpus_y = start_wumpus_y;
	cout<<"reset wumpus y: "<<wumpus_y<<endl;
	cout<<"reset wumpus x: "<<wumpus_x<<endl;
	cave[wumpus_y][wumpus_x]->set_event(2); //sets the class as wumpus using polymorphism
	cave[wumpus_y][wumpus_x]->set_event_num(2); //Set the number as 2 for new wumpus	
	gold = false; //retrieved gold
	is_alive = true; //game ender
	win = false;	// game ender
	wumpus = false;

}

/*Function: get_is_alive
 * Description:used to check if you are still alive or not
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: is_alive is returned
 */
bool Game::get_is_alive(){
	return is_alive;
}


/*Function: get_win
 * Description:used to check if you win
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: win is returned
 */
bool Game::get_win(){
	return win;
}


/*Function: ~Game
 * Description: Game destructor
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: destroys vectors
 */
Game::~Game(){
	cout<<"Vector is destroyed"<<endl;
//	for(int r=0; r< cave_size; r++){
//		for (int c = 0; c < cave_size; c++) {
//			cout<< cave[r][c]->get_event_num()<<endl; //delete the room pointers out here or you can do it inside the destructor
//			delete cave[r][c]; //delete the room pointers out here or you can do it inside the destructor
//		}
//		cave[r].pop_back(); // delete the room*
//	}	
//	cave.pop_back(); //delete cave

}

//Currently vector is freeing some data but not all, it goes into the rooms, might be because not all rooms are pointing to an event
