/*Program Filename:mazelevel.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains mazelevel class
 *Input:none 
 *Output:none
 */
#ifndef MAZELEVEL_H
#define MAZELEVEL_H
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

#include "mazelocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"

using namespace std;
class Mazelevel{
	private:
		Mazelocation*** locations;
		int level_height;
		int level_width;

		int instructor_row;	
		int instructor_col;

	

	public:
		Mazelevel(ifstream& file,int input_height, int input_width);
		void display_mazelevel();
		void set_student(int row, int col);
		void set_student_false(int row, int col);
		void set_ta(int row, int col);
		void set_ta_false(int row, int col);
		bool get_ta(int row, int col);
		bool get_instructor(int row, int col);
		void set_programming_skill(int row, int col);
		void set_programming_skill_false(int row, int col);
		bool get_programming_skill(int row, int col);
		bool get_ladder(int row, int col);
		bool check_is_occupiable(int row, int col);
		int get_instructor_row();
		int get_instructor_col();
		~Mazelevel();


};



#endif
