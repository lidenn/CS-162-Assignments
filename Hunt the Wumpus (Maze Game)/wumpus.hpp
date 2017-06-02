/********
 * Program Filename: wumpus.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the wumpus class
 * Input: None
 * Output: None
 */
#ifndef WUMPUS_H
#define WUMPUS_H

#include"event.hpp"
#include<string>

using namespace std;
class Wumpus : public Event{
	private:
		string warning = "You smell a terrible stench";

	public:
		string get_warning();	


};


#endif
