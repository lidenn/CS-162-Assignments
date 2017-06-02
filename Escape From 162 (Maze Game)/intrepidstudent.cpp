/*Program Filename: instructor.cpp
 *Author:Dennis
 *Date:3/23/17
 *Description:Contains the intrepid student methods
 *Input:None
 *Output:None
 */

#include"intrepidstudent.hpp"
#include<iostream>

Intrepidstudent::Intrepidstudent(){
	row = 1; 
	col = 1;
	programming_skills = 0;
	appease=false;

}
/*Function:get_move
 * Description:gets a character for move
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:char
 */
char Intrepidstudent::get_move(){
	int correct = 1;
	while(correct ==1){
		char c;
		cout<<"Which direction would you like to move?"<<endl;
		cout<<"Programming Skills: "<< programming_skills<<endl;
		cout<<"W for Up"<<endl;
		cout<<"S for Down"<<endl;
		cout<<"A for Right"<<endl;
		cout<<"D for Left"<<endl;
		cout<<"U to go up Ladder"<<endl;
		cout<<"P to demonstate a programming skill"<<endl;
		cin>>c;
		if (c=='w'||c=='s'||c=='a'||c=='d'||c=='u'||c=='p'){
			return c;
		}
	}

}
/*Function:setlocation
 * Description:sets a location for move
 * Parameters:int r, int c
 * Pre-conditions:
 * Post-conditions:none
 */
void Intrepidstudent::set_location(int r , int c){

	this->row = r;
	this->col = c;
}
/*Function:get_row
 * Description:returns user row
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:int for row
 */
int Intrepidstudent::get_row(){
	return row;

}
/*Function:get_col
 * Description:returns user col
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:int for col
 */
int Intrepidstudent::get_col(){
	return col;

}
/*Function:get_programming skills
 * Description:returns programming skills
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:int for skills
 */
int Intrepidstudent::get_programming_skills(){
	return programming_skills;
}

/*Function:change_programming skills
 * Description:increments or decrements programming skills
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions: programming skills are changed
 */
void Intrepidstudent::change_programming_skills(int x){
	if (x==0){
		programming_skills--;
	}
	else if(x==1){
		programming_skills++;
	}
}
/*Function:set_programming skills
 * Description:set programming skills to a specific number, usually 0
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:int for skills
 */
int Intrepidstudent::set_programming_skills(int x){
	programming_skills = x;
}

/*Function:get_appease
 * Description:returns if the user has used an appease
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:bool 
 */
bool Intrepidstudent::get_appease(){
	return appease;
}
/*Function:set_appease
 * Description:if the user has used an appease it sets it
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none 
 */
void Intrepidstudent::set_appease(bool x){
	this->appease = x;
}

