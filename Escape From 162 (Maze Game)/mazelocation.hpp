/*Program Filename:mazelocation.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains mazelocation class
 *Input:none 
 *Output:none
 */
#ifndef MAZELOCATION_H
#define MAZELOCATION_H
using namespace std;
class Mazelocation{
	private:
	public:
		virtual bool is_occupiable() = 0;
		virtual char get_display_character()=0;
		
		virtual void set_has_ladder(bool x){	}
		virtual bool get_has_ladder(){		}
		
		virtual void set_has_starting(bool x){	}
		virtual bool get_has_starting(){	}

		virtual void set_has_instructor(bool x){	}
		virtual bool get_has_instructor(){	}

		virtual void set_has_student(bool x){	}
		virtual bool get_has_student(){	}

		virtual void set_has_ta(bool x){	}
		virtual bool get_has_ta(){	}

		virtual void set_has_programming_skill(bool x){	}
		virtual bool get_has_programming_skill(){	}
};


#endif
