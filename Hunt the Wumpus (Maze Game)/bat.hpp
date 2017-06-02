/********
 * Program Filename: bat.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the bat class
 * Input: None
 * Output: None
 */
#ifndef BAT_H
#define BAT_H

#include"event.hpp"
#include<string>

using namespace std;
class Bat : public Event{
	private:
		string warning = "You hear wings flapping";

	public:
		string get_warning();


};


#endif
