/*Program Filename: sea_otter.cpp
 * Author:Dennis
 * Date:2/20/17
 * Description: file contains the method definitions for class sea_otter
 * Input:none
 * Output:none
 */
#include<iostream>
#include"animal.hpp"
#include"sea_otter.hpp"

using namespace std;

/*Function: Sea otter
 * Description: Default constructor for class sea otter
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */
Sea_otter::Sea_otter(){
	set_age(1095);
	set_cost(5000);
	set_babies(0);
	set_food_cost(2);
	set_revenue(250);
}
