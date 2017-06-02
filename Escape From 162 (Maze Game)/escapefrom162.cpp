/*Program Filename: escapefrom162.cpp
 *Author:Dennis Li
 *Date:3/23/17
 *Description:Game where user naviages through maze and attain skills in order to appease the TA's and Instructor
 *Input:character inputs for direction
 *Output:Win or Lose
 */
#include<iostream>
#include<fstream>
#include<string>

#include "mazelevel.hpp"
#include "mazelocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include "maze.hpp"

#include "mazeperson.hpp"

using namespace std;
/*Function:main
 * Description:Creates a maze and runs the game
 * Parameters:.txt
 * Pre-conditions:text file for preset maze
 * Post-conditions:none
 */
int main(int argc, char** argv){
	ifstream maze_data;
	maze_data.open(argv[1]);
	if(maze_data.fail()){
		cout<<"Can't enter into maze file"<<endl;
		return 0;
	}


	Maze m(maze_data);  //Properly assigning and printing it correctly	
	bool win = false;
	m.randomize_TA();
	m.randomize_programming_skill();
	m.randomize_programming_skill();
	while(win == false){
		m.display_maze();
		cout<<endl;
		m.player_move();
		m.TA1_move();
		m.TA2_move();
		m.run_into_TA();
		m.run_into_instructor();
		win = m.get_Win();
	}
}

