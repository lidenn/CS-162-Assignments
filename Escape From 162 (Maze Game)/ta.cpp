/*Program Filename: instructor.cpp
 *Author:Dennis
 *Date:3/23/17
 *Description:Contains the ta methods
 *Input:None
 *Output:None
 */

#include"ta.hpp"
#include<iostream>
#include<cstdlib>
Ta::Ta(){

	srand(time(NULL));

}
/*Function:get_move
 * Description:gets a character for move
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:char
 */
char Ta::get_move(){
	int num =  rand()%4;
	if(num ==0){
		return 'w';
	}	
	else if(num ==1){
		return 's';
	}
	else if(num ==2){
		return 'a';
	}
	else if(num ==3){
		return 'd';
	}
}
/*Function:setlocation
 * Description:sets a location for move
 * Parameters:int r, int c
 * Pre-conditions:
 * Post-conditions:none
 */
void Ta::set_location(int r , int c){

	this->row = r;
	this->col = c;
}
/*Function:get_row
 * Description:returns user row
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:int for row
 */
int Ta::get_row(){
	return row;
}
/*Function:get_col
 * Description:returns user col
 * Parameters:none
 * Pre-conditions:
 * Post-conditions:int for col
 */
int Ta::get_col(){
	return col;
}

