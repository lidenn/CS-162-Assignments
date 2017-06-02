/*Program Filename: instructor.cpp
 *Author:Dennis
 *Date:3/23/17
 *Description:Contains the mazelevel methods
 *Input:None
 *Output:None
 */

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

#include"mazelevel.hpp"
#include "wall.hpp"
#include "openspace.hpp"

/*Function:Maze
 * Description:sets up an 2Darray of Mazelocations 
 * Parameters:ifstream
 * Pre-conditions:maze data
 * Post-conditions:none
 */
Mazelevel::Mazelevel(ifstream& file,int input_height, int input_width){
	srand(time(NULL));	
	level_height = input_height;
	level_width = input_width;
	locations = new Mazelocation ** [level_height];	
	for(int r =0; r<level_height; r++){
		locations [r] = new Mazelocation * [level_height];	
	}
	for(int	r =0; r<input_height; r++){
		for(int	c =0; c<input_width; c++){
			char temp;
			file.get(temp);
			if (temp == '#' ){
				locations[r][c]=new Wall;
			}
			else if (temp == ' ' ){
				locations[r][c]=new Openspace;
			}
			else if(temp == '@'  ){
				locations[r][c]=new Openspace;
				locations[r][c]->set_has_starting(true);
				locations[r][c]->set_has_student(true);
			}
			else if (temp == '^' ){
				locations[r][c]=new Openspace;
				locations[r][c]->set_has_ladder(true);
			}	
			else if (temp == '%' ){
				locations[r][c]=new Openspace;			
				instructor_row=  r;
				instructor_col=  c;
				locations[r][c]->set_has_instructor(true);
			}	
			else{
				c=c-1; //This is so that it doesn't increment for new line(\n)

			}

			if(file.eof()){
				return;
			}
		}
		cout<<endl;
	}

	locations[1][1]->set_has_student(true);


}



/*Function:display_mazelevel
 * Description:Displays the 2d array
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */

void Mazelevel::display_mazelevel(){
	for(int	r =0; r<level_height; r++){
		for(int	c =0; c<level_width; c++){
			if(locations[r][c]->is_occupiable() ==true && locations[r][c]->get_has_student() == true) {
				cout<<'*';
			}
			else if(locations[r][c]->is_occupiable() ==true && locations[r][c]->get_has_ta() == true ){  //These if statements check the method is true and if it is an empty space
				cout<<'T';
			}
			else if(locations[r][c]->is_occupiable() ==true && locations[r][c]->get_has_programming_skill() == true ){  
				cout<<'$';
			}
			else if(locations[r][c]->is_occupiable() ==true && locations[r][c]->get_has_ladder() == true ){  //These if statements check the method is true and if it is an empty space
				cout<<'^';
			}
			else if(locations[r][c]->is_occupiable() ==true && locations[r][c]->get_has_starting() == true) {
				cout<<'@';
			}
			else if(locations[r][c]->is_occupiable() ==true && locations[r][c]->get_has_instructor() == true) {
				cout<<'%';
			}

			else{
				cout<<locations[r][c]->get_display_character();
			}

		}
		cout<<endl;
	}	

}
/*Function:set_student
 * Description:Places student in a certain spot on array
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */


void Mazelevel::set_student(int row, int col){
	locations[row][col]->set_has_student(true);
}
/*Function:set_student_false
 * Description:removes student in a certain spot on array
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
void Mazelevel::set_student_false(int row, int col){
	locations[row][col]->set_has_student(false);
}

/*Function:set_ta
 * Description:Places ta in a certain spot on array
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
void Mazelevel::set_ta(int row, int col){
	locations[row][col]->set_has_ta(true);
}
/*Function:set_ta_false
 * Description:removes ta in a certain spot on array
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
void Mazelevel::set_ta_false(int row, int col){
	locations[row][col]->set_has_ta(false);
}
/*Function:get_ta
 * Description:returns ta
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
bool Mazelevel::get_ta(int row, int col){
	return locations[row][col]->get_has_ta();
}
/*Function:get_instructor
 * Description:returns instructor
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
bool Mazelevel::get_instructor(int row, int col){
	return locations[row][col]->get_has_instructor();
}
/*Function:set_programming skill
 * Description:Places programming skill in a certain spot on array
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
void Mazelevel::set_programming_skill(int row, int col){
	locations[row][col]->set_has_programming_skill(true);
}/*Function:set_programming skill_false
 * Description:removes programming skill in a certain spot on array
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
void Mazelevel::set_programming_skill_false(int row, int col){
	locations[row][col]->set_has_programming_skill(false);
}
/*Function:get_programming skill
 * Description:returns programming skill
 * Parameters:int int
 * Pre-conditions:none
 * Post-conditions:changed array
 */
bool Mazelevel::get_programming_skill(int row, int col){
	return locations[row][col]->get_has_programming_skill();
}


bool Mazelevel::get_ladder(int row, int col){
	return locations[row][col]->get_has_ladder();
}

bool Mazelevel::check_is_occupiable(int row, int col){
	return locations[row][col]->is_occupiable();

}

int Mazelevel::get_instructor_row(){
	return instructor_row;
}	
int Mazelevel::get_instructor_col(){
	return instructor_col;
}	




Mazelevel::~Mazelevel(){

	/*	for(int r =0; r<level_height; r++){
		for(int	c =0; c<level_width; c++){
		delete locations[r][c];
		}
		delete []locations [r]; 		
		}
		delete []locations;
		*/
}


