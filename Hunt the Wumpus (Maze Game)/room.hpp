/********
 * Program Filename: room.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the room class
 * Input: None
 * Output: None
 */
#ifndef ROOM_H
#define ROOM_H

#include"event.hpp"
#include"wumpus.hpp"
#include"gold.hpp"
#include"pit.hpp"
#include"bat.hpp"
#include"empty.hpp"

using namespace std;

class Room{
	private:
		int event_num;
		bool adventurer;
		Event* eptr;

	public:

		Room();  //Depending on event num, set the eptr to certain event(wumpus, empty, etc) using poly

		int get_event_num();

		void set_event_num(int num);

		bool get_adventurer();
		void set_adventurer(bool x);
		void print_wumpus();
		void delete_event();
		void set_event(int option);
		string get_event_warning();   //Get event will return the warning from the abstract class of event (depend on pointing to what)
		~Room();

};

#endif
