/*Program Filename:maze.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains maze class
 *Input:none 
 *Output:none
 */
#ifndef MAZE_H
#define MAZE_H
#include<cstdlib>
#include "mazelevel.hpp"
#include "mazeperson.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"
using namespace std;
class Maze{
	private:
		int num_levels;
		int level_height;
		int level_width;
		int current_level;
		int appease_counter;

		Mazelevel** mazelevels;
		Mazeperson * student;
		Mazeperson * TA1;
		Mazeperson * TA2;
		Mazeperson * instructor;

		bool Win;

	public:

		Maze(ifstream& maze_data);
		void randomize_TA();
		void randomize_programming_skill();
		void display_maze();
		void player_move();
		void TA1_move();
		void TA2_move();				
		void run_into_TA();
		void run_into_instructor();
		bool get_Win();
		




};


#endif
