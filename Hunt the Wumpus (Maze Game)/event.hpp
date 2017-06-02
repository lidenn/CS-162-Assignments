/********
 * Program Filename: event.hpp
 * Author:Dennis Li
 * Date: 3/7/17
 * Description: Contains the event class
 * Input: None
 * Output: None
 */
#ifndef EVENT_H
#define EVENT_H



using namespace std;
class Event{
	private:
		string warning = "Event warning";
	public:
		virtual string get_warning() =0; //This causes it to be abstract, so must be a base class and must be declared as pointer
		//virtual ~Event(){
			//cout<<"in event destructor"<<endl;
		//}	

};


#endif
