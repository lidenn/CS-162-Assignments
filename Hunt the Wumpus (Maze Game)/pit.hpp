/********
 * Program Filename: pit.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the pit class
 * Input: None
 * Output: None
 */
#ifndef PIT_H
#define PIT_H

#include"event.hpp"
#include<string>

using namespace std;
class Pit : public Event{
	private:
		string warning = "You feel a breeze";

	public:
		string get_warning();


};


#endif
