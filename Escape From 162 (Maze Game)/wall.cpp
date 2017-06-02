/*Program Filename: instructor.cpp
 *Author:Dennis
 *Date:3/23/17
 *Description:Contains the wall methods
 *Input:None
 *Output:None
 */

#include"wall.hpp"
/*Function:Wall
 * Description: Sets occupiable as false and character as #
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:none
 */

Wall::Wall(){
	occupiable = false;
	display_character = '#';
}
/*Function:is_occupiable
 * Description: occupiable
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:returns occupiable
 */
bool Wall::is_occupiable(){ 
	return occupiable;
}
/*Function:get_display_character
 * Description: Returns display_character
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:bool Win
 */
char Wall::get_display_character(){
	return display_character;
}
