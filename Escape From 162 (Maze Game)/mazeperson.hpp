/*Program Filename:mazeperson.hpp
 *Author:Dennis
 *Date:3/23/17
 *Description:contains mazepersonclass
 *Input:none 
 *Output:none
 */
#ifndef MAZEPERSON_HPP
#define MAZEPERSON_HPP
using namespace std;

class Mazeperson{
	private:

	public:
		virtual char get_move()=0;
		virtual void set_location(int, int)=0;
		virtual int get_row()=0;
		virtual int get_col()=0;
		virtual int get_programming_skills(){
		}
		virtual void change_programming_skills(int x){
		}
		virtual bool get_appease(){
		}
		virtual void set_appease(bool x){
		}
		virtual int set_programming_skills(int ){
		}



};


#endif
