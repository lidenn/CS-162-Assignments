/*Program Filename:open space.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains open space class
 *Input:none 
 *Output:none
 */
#ifndef OPENSPACE_H
#define OPENSPACE_H
#include"mazelocation.hpp"
using namespace std;
class Openspace: public Mazelocation{
	private:
		bool occupiable;
		char display_character;

		bool has_student;
		bool has_ta;
		bool has_instructor;
		bool has_ladder;
		bool has_skill;
		bool has_starting;
		bool has_programming_skill;
	public:
		Openspace();

		bool is_occupiable();
		virtual char get_display_character();
		void set_has_student(bool x);
		void set_has_ta(bool x);
		void set_has_instructor(bool x);
		 void set_has_ladder(bool x);
		void set_has_skill(bool x);
		void set_has_starting(bool x);
		void set_has_programming_skill(bool x);
		bool get_has_student();
		bool get_has_ta();
		bool get_has_instructor();
		bool get_has_ladder();
		bool get_has_skill();
		bool get_has_starting();
		bool get_has_programming_skill();
};


#endif
