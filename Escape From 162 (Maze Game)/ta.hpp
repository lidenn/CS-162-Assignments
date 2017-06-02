/*Program Filename:ta.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains ta class
 *Input:none 
 *Output:none
 */
#ifndef TA_H
#define TA_H

#include<cstdlib>
#include "mazeperson.hpp"

class Ta: public Mazeperson{
	private:
		int row;
		int col;

	public:
		Ta();
		char get_move();
		void set_location(int r , int c);
		int get_row();
		int get_col();




};



#endif
