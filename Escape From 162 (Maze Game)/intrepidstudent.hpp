/*Program Filename:intrepidstudent.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains student class
 *Input:none 
 *Output:none
 */
#ifndef INTREPIDSTUDENT_H
#define INTREPIDSTUDENT_H

#include "mazeperson.hpp"

class Intrepidstudent: public Mazeperson{
	private:
		int row;
		int col;
		int programming_skills;
		bool appease;

	public:
		Intrepidstudent();
		char get_move();
		void set_location(int r , int c);
		int get_row();
		int get_col();
		int get_programming_skills();
		void change_programming_skills(int x);
		int set_programming_skills(int x);
		bool get_appease();
		void set_appease(bool x);



};



#endif
