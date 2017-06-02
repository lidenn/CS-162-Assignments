/*Program Filename: sloth cpp
 * Author:Dennis
 * Date:2/20/17
 * Description: file contains the method definitions for class sloth
 * Input:none
 * Output:none
 */
#include<iostream>
#include"animal.hpp"
#include"sloth.hpp"

using namespace std;

/*Function: Sloth
 * Description: Default constructor for class sloth
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */
Sloth::Sloth(){
	set_age(1095);
	set_cost(2000);
	set_babies(0);
	set_food_cost(1);
	set_revenue(100);
}
