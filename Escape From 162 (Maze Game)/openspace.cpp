/*Program Filename: instructor.cpp
 *Author:Dennis
 *Date:3/23/17
 *Description:Contains the openspace methods
 *Input:None
 *Output:None
 */

#include"openspace.hpp"
//Program contains accessors and mutators for and open space, where the open space is set as occupiable and everything else as false

Openspace::Openspace(){
	occupiable = true;
	display_character = ' ';
	has_student=false;
	has_ta=false;
	has_instructor=false;
	has_ladder=false;
	has_skill=false;
	has_starting=false;
	has_programming_skill= false;

}
/*Function:is_occupiable
 * Description: occupiable
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:returns occupiable
 */
bool Openspace::is_occupiable(){ 
	return occupiable;

}
/*Function:get_display_character
 * Description: Returns display_character
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:bool Win
 */
char Openspace::get_display_character(){
	return display_character;

}

void Openspace::set_has_student(bool x){
	has_student = x;	
}
void Openspace::set_has_ta(bool x){
	has_ta = x;
}
void Openspace::set_has_instructor(bool x){
	has_instructor = x;
}
void Openspace::set_has_ladder(bool x){
	has_ladder = x;
}
void Openspace::set_has_skill(bool x){
	has_skill = x;
}
void Openspace::set_has_starting(bool x){
	has_starting = x;
}
void Openspace::set_has_programming_skill(bool x){
	has_programming_skill = x;
}

bool Openspace::get_has_student(){
	return has_student;
}
bool Openspace::get_has_ta(){
	return has_ta;
}	
bool Openspace::get_has_instructor(){
	return has_instructor;
}
bool Openspace::get_has_ladder(){
	return has_ladder;
}
bool Openspace::get_has_skill(){
	return has_skill;
}
bool Openspace::get_has_starting(){
	return has_starting;
}
bool Openspace::get_has_programming_skill(){
	return has_programming_skill;
}

