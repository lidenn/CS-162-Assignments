#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>


#include"room.hpp"
#include"event.hpp"
#include"wumpus.hpp"
using namespace std; //This means we can't create something called vector
int main(int argc, char** argv){
	srand(time(NULL));
	int size = atoi(argv[1]);


	std::vector<std::vector<Room> > vec2d(size);
	for (int i = 0; i < size; i++) {
		std::vector<Room> row(size);
		vec2d[i] = row; //Connecting vec2d equal to the row you created
	}
	for (int i=0;i<size;i++){
		for (int j = 0; j < size; j++) {
			vec2d[i][j].set_event_num((rand()%4)+1);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << " " << vec2d[i][j].get_event_num();
		}
		std::cout << std::endl;
	}


}

