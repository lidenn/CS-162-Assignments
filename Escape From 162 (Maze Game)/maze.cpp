/*Program Filename: instructor.cpp
 *Author:Dennis
 *Date:3/23/17
 *Description:Contains the maze methods
 *Input:None
 *Output:None
 */

#include<cstdlib>
#include "maze.hpp"
#include "mazelevel.hpp"
#include "mazeperson.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"
using namespace std;
/*Function:Maze
 * Description:sets up an array of Mazelevels with the people involved in the games
 * Parameters:ifstream
 * Pre-conditions:maze data
 * Post-conditions:none
 */
Maze::Maze(ifstream& maze_data){
	srand(time(NULL));
	Win = false; //Keeps game going

	student = new Intrepidstudent;
	TA1 = new Ta;
	TA2 = new Ta;
	instructor = new Instructor;
	current_level = 0;
	appease_counter=10;

	maze_data>>num_levels; 
	cout<<num_levels<<endl;

	maze_data>>level_height;
	cout<<level_height<<endl;

	maze_data>>level_width;
	cout<<level_width<<endl;


	mazelevels = new Mazelevel * [num_levels]; //Declares an array for the mazelevel*'s
	for(int i=0; i<num_levels; i++){
		mazelevels[i] = new Mazelevel(maze_data, level_height, level_width);
		cout<<endl;
	}
}
/*Function:randomizeTA
 * Description:sets TA randomly
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::randomize_TA(){
	bool TA_valid = false;
	while (TA_valid ==false){
		TA1->set_location(rand()%17, rand()%17);
		TA2->set_location(rand()%17, rand()%17);


		if((mazelevels[current_level]->check_is_occupiable(TA1->get_row(), TA1->get_col())==true)&&(mazelevels[current_level]->check_is_occupiable(TA2->get_row(), TA2->get_col())==true)){
			mazelevels[current_level]->set_ta(TA1->get_row(), TA1->get_col());
			mazelevels[current_level]->set_ta(TA2->get_row(), TA2->get_col());
			TA_valid = true;
		}
	}

}
/*Function:randomizeprogrammingskill
 * Description:sets programming skills randomly
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::randomize_programming_skill(){
	bool skill_valid = false;
	while (skill_valid ==false){
		int skill_row = rand()%17;
		int skill_col = rand()%17;

		if((mazelevels[current_level]->check_is_occupiable(skill_row, skill_col)==true)){
			mazelevels[current_level]->set_programming_skill(skill_row, skill_col);
			skill_valid = true;
		}
	}

}


//When working on TA, you must be able to remove the TA from OLD when moving such as remove_old_Ta and TA_move

/*Function:display maze
 * Description:display maze
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::display_maze(){
	mazelevels[current_level]->display_mazelevel();
}
/*Function:player move
 * Description:based on user input, it decides on what to do next and also calculates the interface with the game
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::player_move(){
	char direction;
	direction = student->get_move();
	int student_row = student->get_row();
	int student_col = student->get_col();
	if (direction == 'w'&& mazelevels[current_level]->check_is_occupiable(student_row-1,student_col)){  //Checks if it is occupiable and uses information from student class

		mazelevels[current_level]->set_student_false(student_row,student_col);			//Sets old location as false 
		student->set_location((student_row)-1, student_col);					//changes row and columns in class
		mazelevels[current_level]->set_student(student->get_row(),student->get_col()); //Important: the row in the class has changed but now student row or student col
	}		
	else if (direction == 's'&& mazelevels[current_level]->check_is_occupiable(student_row+1,student_col)){
		mazelevels[current_level]->set_student_false(student_row,student_col); 
		student->set_location((student_row)+1, student_col);
		mazelevels[current_level]->set_student(student->get_row(),student->get_col());

		student_row = student->get_row();
		student_col = student->get_col();

	}		
	else if (direction == 'a'&& mazelevels[current_level]->check_is_occupiable(student_row,student_col-1)){
		mazelevels[current_level]->set_student_false(student_row,student_col); 
		student->set_location((student_row), student_col-1);
		mazelevels[current_level]->set_student(student->get_row(),student->get_col());
	}
	else if (direction == 'd'&& mazelevels[current_level]->check_is_occupiable(student_row,student_col+1)){
		mazelevels[current_level]->set_student_false(student_row,student_col); 
		student->set_location((student_row), student_col+1);
		mazelevels[current_level]->set_student(student->get_row(),student->get_col()); 

	}
	else if(direction == 'u'){								//In this scenario, the player is trying to go up a level
		if(mazelevels[current_level]->get_ladder(student->get_row(),student->get_col())==true){
		current_level++;
		student->set_location(1,1);
		randomize_TA();
		randomize_programming_skill();
		randomize_programming_skill();
		student->set_appease(false);		//Change appease	
		}
	}
	else if(direction == 'p'){	
		if(student->get_programming_skills()>0){
			student->set_appease(true);		//Change appease	
			student->change_programming_skills(0);  //decrement programming skill
		}
	}

	////This part of move is to check if there is a programming skill
	if(mazelevels[current_level]->get_programming_skill(student->get_row(), student->get_col())==true){
		cout<<" You have picked up a programming skill"<<endl;
		student->change_programming_skills(1);
		mazelevels[current_level]->set_programming_skill_false(student->get_row(), student->get_col());  //Set false after you pick up

	}
	if(student->get_appease()==true){
		cout<<"Appease turns left "<<appease_counter<<endl;
		appease_counter--;
		if (appease_counter == 0){
			appease_counter = 10;
			student->set_appease(false);
		}
	}
}
/*Function:TA move
 * Description:randomly moves TA as an Ai throught the game
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::TA1_move(){
	char direction;
	int curr_row = TA1->get_row();
	int curr_col = TA1->get_col();
	direction = TA1->get_move();
	bool valid_move = false;
	while(valid_move == false){
		if (direction == 'w'&& mazelevels[current_level]->check_is_occupiable(curr_row-1,curr_col)){  //Checks if it is occupiable and uses information from student class
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);			     // if location works, it will set the old array location false
			TA1->set_location(curr_row-1,curr_col);						    //Change the TA row and col	
			mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());		//Set the array at new row and col as true	
			valid_move = true;

		}		
		else if (direction == 's'&& mazelevels[current_level]->check_is_occupiable(curr_row+1,curr_col)){
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA1->set_location(curr_row+1,curr_col);
			mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
			valid_move = true;

		}		
		else if (direction == 'a'&& mazelevels[current_level]->check_is_occupiable(curr_row,curr_col-1)){
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA1->set_location(curr_row,curr_col-1);
			mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
			valid_move = true;

		}
		else if (direction == 'd'&& mazelevels[current_level]->check_is_occupiable(curr_row,curr_col+1)){
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA1->set_location(curr_row,curr_col+1);
			mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
			valid_move = true;

		}
		else{ //If the original get_char() is a non occupiable space it will generate a new letter here
			int num =  rand()%4;
			if(num ==0){
				direction = 'w';
			}	
			else if(num ==1){
				direction ='s';
			}
			else if(num ==2){
				direction ='a';
			}
			else if(num ==3){
				direction ='d';
			}

		}
	}
}
/*Function:TA move
 * Description:randomly moves TA as an Ai throught the game
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */

void Maze::TA2_move(){ 				//Copy of the one above, but simply for TA2
	char direction;
	int curr_row = TA2->get_row();		//The before row and column
	int curr_col = TA2->get_col();
	direction = TA2->get_move();
	bool valid_move = false;
	while(valid_move == false){
		if (direction == 'w'&& mazelevels[current_level]->check_is_occupiable(curr_row-1,curr_col)){  //Checks if it is occupiable and uses information from student class
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA2->set_location(curr_row-1,curr_col);
			mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
			valid_move = true;

		}		
		else if (direction == 's'&& mazelevels[current_level]->check_is_occupiable(curr_row+1,curr_col)){
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA2->set_location(curr_row+1,curr_col);
			mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
			valid_move = true;

		}		
		else if (direction == 'a'&& mazelevels[current_level]->check_is_occupiable(curr_row,curr_col-1)){
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA2->set_location(curr_row,curr_col-1);
			mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
			valid_move = true;

		}
		else if (direction == 'd'&& mazelevels[current_level]->check_is_occupiable(curr_row,curr_col+1)){ 
			mazelevels[current_level]->set_ta_false(curr_row, curr_col);
			TA2->set_location(curr_row,curr_col+1);
			mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
			valid_move = true;

		}
		else{ //If the original get_char() is a non occupiable space it will generate a new letter here
			int num =  rand()%4;
			if(num ==0){
				direction = 'w';
			}	
			else if(num ==1){
				direction ='s';
			}
			else if(num ==2){
				direction ='a';
			}
			else if(num ==3){
				direction ='d';
			}

		}
	}
}
/*Function:run into TA
 * Description: Reveals result after running into a TA
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::run_into_TA(){
	int student_row = student->get_row();
	int student_col = student->get_col();
	mazelevels[current_level]->check_is_occupiable(student_row,student_col);
	if(student->get_appease()==false){  //0 for false, 1 for true
		if(mazelevels[current_level]->check_is_occupiable(student_row,student_col) && mazelevels[current_level]->get_ta(student_row, student_col)== true){ //Check if space is occupiable and occupied by TA
			cout<<"You've ran into a TA"<<endl;
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			student->set_programming_skills(0);
		}	
		else if(mazelevels[current_level]->check_is_occupiable(student_row+1,student_col) && mazelevels[current_level]->get_ta(student_row+1, student_col)== true){
			cout<<"You've ran into a TA"<<endl;
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			student->set_programming_skills(0);
		}		
		else if(mazelevels[current_level]->check_is_occupiable(student_row-1,student_col)&&mazelevels[current_level]->get_ta(student_row-1, student_col)== true){
			cout<<"You've ran into a TA"<<endl;
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			student->set_programming_skills(0);
		}		
		else if(mazelevels[current_level]->check_is_occupiable(student_row,student_col+1)&&mazelevels[current_level]->get_ta(student_row, student_col+1)== true){
			cout<<"You've ran into a TA"<<endl;
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			student->set_programming_skills(0);
		}		
		else if(mazelevels[current_level]->check_is_occupiable(student_row,student_col-1)&&mazelevels[current_level]->get_ta(student_row, student_col-1)== true){
			cout<<"You've ran into a TA"<<endl;
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			student->set_programming_skills(0);
		}
	}

}
/*Function:run into Instructor
 * Description: Reveals result after running into a Instructor
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */
void Maze::run_into_instructor(){
	if(mazelevels[current_level]->get_instructor_row() >0 &&mazelevels[current_level]->get_instructor_col()>0){
		instructor->set_location(mazelevels[current_level]->get_instructor_row(),mazelevels[current_level]->get_instructor_col());
	}

	int student_row = student->get_row();
	int student_col = student->get_col();
	mazelevels[current_level]->check_is_occupiable(student_row,student_col);
	if(mazelevels[current_level]->check_is_occupiable(student_row,student_col) && mazelevels[current_level]->get_instructor(student_row, student_col)== true){ //Check if space is occupiable and occupied by TA
		cout<<"You've ran into a Instructor"<<endl;
		if(student->get_programming_skills()<3){
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			current_level = 0;
			student->set_programming_skills(0);
		}
		else{
			cout<<"More than 3 programming skills!"<<endl;
			cout<<"YOU WIN!"<<endl;
			Win = true;
		}
	}
	else if(mazelevels[current_level]->check_is_occupiable(student_row+1,student_col) && mazelevels[current_level]->get_instructor(student_row+1, student_col)== true){
		cout<<"You've ran into a Instructor"<<endl;
		if(student->get_programming_skills()<3){
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			current_level = 0;
			student->set_programming_skills(0);
		}			
		else{
			cout<<"More than 3 programming skills!"<<endl;
			cout<<"YOU WIN!"<<endl;
			Win = true;
		}
	}
	else if(mazelevels[current_level]->check_is_occupiable(student_row-1,student_col)&&mazelevels[current_level]->get_instructor(student_row-1, student_col)== true){
		cout<<"You've ran into a Instructor"<<endl;
		if(student->get_programming_skills()<3){
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			current_level = 0;
			student->set_programming_skills(0);
		}			
		else{
			cout<<"More than 3 programming skills!"<<endl;
			cout<<"YOU WIN!"<<endl;
			Win = true;
		}
	}
	else if(mazelevels[current_level]->check_is_occupiable(student_row,student_col+1)&&mazelevels[current_level]->get_instructor(student_row, student_col+1)== true){
		cout<<"You've ran into a Instructor"<<endl;
		if(student->get_programming_skills()<3){
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			current_level = 0;
			student->set_programming_skills(0);
		}			
		else{
			cout<<"More than 3 programming skills!"<<endl;
			cout<<"YOU WIN!"<<endl;
			Win = true;
		}
	}
	else if(mazelevels[current_level]->check_is_occupiable(student_row,student_col-1)&&mazelevels[current_level]->get_instructor(student_row, student_col-1)== true){
		cout<<"You've ran into a Instructor"<<endl;
		if(student->get_programming_skills()<3){
			mazelevels[current_level]->set_student_false(student_row,student_col); 
			student->set_location(1,1);
			current_level = 0;
			student->set_programming_skills(0);
		}
		else{
			cout<<"More than 3 programming skills!"<<endl;
			cout<<"YOU WIN!"<<endl;
			Win = true;
		}
	}

}
/*Function:get_Win
 * Description: Returns win as true
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:bool Win
 */
bool Maze::get_Win(){
	return Win;
}
