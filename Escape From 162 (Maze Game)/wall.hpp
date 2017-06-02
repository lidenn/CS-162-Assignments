/*Program Filename:wall.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains wall class
 *Input:none 
 *Output:none
 */
#ifndef WALL_H
#define WALL_H
using namespace std;
#include"mazelocation.hpp"
class Wall: public Mazelocation{
	private:
		bool occupiable;
		char display_character;
	public:
		Wall();
		//	occupiable = false;
		//	display_character = '#';
		//}

		bool is_occupiable();
		//	return occupiable;
		//}
		char get_display_character();
		//	return display_character;
		//}

};


#endif
