/********
 * Program Filename: gold.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the gold class
 * Input: None
 * Output: None
 */
#ifndef GOLD_H
#define GOLD_H

#include"event.hpp"
#include<string>

using namespace std;
class Gold : public Event{
	private:
		string warning = "You see a glimmer nearby";

	public:
		string get_warning();


};


#endif
