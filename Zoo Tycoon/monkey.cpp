/*Program Filename: monkey.cpp
 * Author:Dennis
 * Date:2/20/17
 * Description: file contains the method definitions for class monkey
 * Input:none
 * Output:none
 */
#include<iostream>
#include"animal.hpp"
#include"monkey.hpp"

using namespace std;

/*Function: Monkey
 * Description: Default constructor for class monkey
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */
Monkey::Monkey(){
	set_age(1095);
	set_cost(15000);
	set_babies(0);
	set_food_cost(4);
	set_revenue(1500);
}

