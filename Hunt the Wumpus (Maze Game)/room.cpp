/********
 * Program Filename: Room.cpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the room functions for hunt the wumpus
 * Input: None
 * Output: None
 */
#include<iostream>
#include<cstdlib>

#include"event.hpp"
#include"wumpus.hpp"
#include"gold.hpp"
#include"pit.hpp"
#include"bat.hpp"
#include"empty.hpp"
#include"room.hpp"

using namespace std;
/*Function: Room 
 * Description: Class constructor for room
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: creates a room class
 */
Room::Room(){  //Depending on event num, set the eptr to certain event(wumpus, empty, etc) using poly
	srand(time(NULL));
	event_num = 0;  //Set as empty room
	adventurer = false;
}

/*Function: get event num 
 * Description: returns event num
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: event num
 */
int Room::get_event_num(){
	return event_num;
}

/*Function: set event num 
 * Description: sets event num
 * Parameters: int
 * Pre-conditions: number
 * Post-conditions: set event num
 */
void Room::set_event_num(int num){
	event_num = num;
}

/*Function: get adventurer 
 * Description: returns adventurer
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: adventurer
 */
bool Room::get_adventurer(){
	return adventurer;
}

/*Function: set adventurer 
 * Description: sets adventurer
 * Parameters: int
 * Pre-conditions: number
 * Post-conditions: set adventurer
 */
void Room::set_adventurer(bool x){
	if(x==true){
		adventurer = true;
	}
	if(x==false){
		adventurer = false;
	}

}


//void Room::print_wumpus(){
//	cout<<"in the room"<<endl;
//	cout<<eptr->get_warning()<<endl;
//
//}

/*Function: delete event
 * Description: deletes eptr
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: deletes and makes new eptr
 */
void Room::delete_event(){
	delete eptr;
	Event* eptr;
}

/*Function: set event 
 * Description: sets specific event through eptr
 * Parameters: int
 * Pre-conditions: number for option
 * Post-conditions: set eptr to new
 */
void Room::set_event(int option){
	if(option ==2){
		eptr= new Wumpus;
		cout<<"created new wumpus"<<endl;
	}
	else if(option ==3){
		eptr= new Gold;		
	}
	else if(option ==4){
		eptr= new Pit;		
	}
	else if(option ==5){
		eptr= new Bat;	
	}
	else{
		eptr = new Empty;
	}



}

/*Function: get event warning
 * Description: gets specific warning
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: gets the specific warning
 */
string Room::get_event_warning(){    //Get event will return the warning from the abstract class of event (depend on pointing to what)
	string warning = eptr->get_warning();
	return warning;
}



/*Function: ~Room
 * Description: Room destructor
 * Parameters: none
 * Pre-conditions:None
 * Post-conditions: destroys eptr
 */
Room::~Room(){
	cout<<"Room destructor"<<endl;
		//cout<< "event num: "<<event_num<<endl;//  This is causing a segfault
		//delete  eptr;//  This is causing a segfault
}
