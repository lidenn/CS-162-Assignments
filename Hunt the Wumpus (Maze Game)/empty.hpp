/********
 * Program Filename: empty.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the empty class
 * Input: None
 * Output: None
 */
#ifndef EMPTY_H
#define EMPTY_H

#include"event.hpp"
#include<string>

using namespace std;
class Empty : public Event{
	private:
		string warning = "No event";

	public:
		string get_warning();


};


#endif
