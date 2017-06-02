/*Program Filename: Animal.hpp
 * Author:Dennis
 * Date:2/20/17
 * Description: Animal class's data and methods
 * Input:none
 * Output:none
 */
#include<iostream>
#ifndef ANIMAL_H
#define ANIMAL_H
class Animal{
	protected:
		int age;
		int cost;
		int babies;
		float food_cost;
		int revenue;
		bool is_sick;

	public:
		Animal();
		int get_age();
		int get_cost();
		int get_babies();
		float get_food_cost();
		int get_revenue();
		void set_age(int x);
		void set_cost(int x);
		void set_babies(int x);
		void set_food_cost(float x);
		void set_revenue(int x);
		void add_babies(int x);


};
#endif

