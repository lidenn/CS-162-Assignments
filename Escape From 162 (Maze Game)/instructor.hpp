/*Program Filename:instructor.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains instructor class
 *Input:none 
 *Output:none
 */
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include<cstdlib>
#include "mazeperson.hpp"

class Instructor: public Mazeperson{
	private:
		int row;
		int col;

	public:
		Instructor();
		char get_move();
		void set_location(int r , int c);
		int get_row();
		int get_col();





};



#endif
