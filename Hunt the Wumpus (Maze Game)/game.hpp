/********
 * Program Filename: game.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the game class
 * Input: None
 * Output: None
 */

#ifndef GAME_H
#define GAME_H

#include<vector>
#include<iostream>
#include<cstdlib>
#include<string>

#include"room.hpp"
#include"event.hpp"
#include"wumpus.hpp"
using namespace std;

class Game{
	private:
		int cave_size;
		vector<vector<Room*> >cave;
		int user_x, user_y;
		int start_user_x, start_user_y; //to remember starting point of user for new game

		int arrow_x, arrow_y; //location of arrows
		int arrows = 3; // number of arrows

		int wumpus_x, wumpus_y; //location of wumpus
		int start_wumpus_x, start_wumpus_y; //location of wumpus
		bool wumpus = false;	//wumpus killed

		bool gold = false; //retrieved gold
		bool is_alive = true; //game ender
		bool win = false;	// game ender
	public:
		Game(int size);
	

		void print_nearby_event(); 

		void print_board();
	
		void set_board(); 

		void print_adventurer_board();
		

		void move_adventurer(int direction); 
		void shoot_arrow(int direction);
		
		void run_event(); 
		bool check_is_alive();
		void game_reset();
		
		bool get_is_alive();
	
		bool get_win();
		
		~Game();
};

#endif




//CURRENTLY SEGFAULTING IN THE DESTRUCTOR, IT NEEDS TO DESTRUCT EPTR
