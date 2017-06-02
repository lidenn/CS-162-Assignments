/********
 * Program Filename: Hunt_the_wumpus.cpp
 * Author: Dennis Li
 * Date: 3/7/17
 * Description: Program runs the game hunt the wumpus, where the user must kill the wumpus and take the gold to win
 * Input: User inputs numbers for certain moves
 * Output: Displays win-status and game board
 */


#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>


#include"room.hpp"
#include"event.hpp"
#include"wumpus.hpp"
#include"game.hpp"

using namespace std; //This means we can't create something called vector


/*Function: Main
 * Description: Runs the hunt the wumpus game
 * Parameters: Int
 * Pre-conditions: Int for board size
 * Post-conditions: Finished game, player can choose to play again or stop
 */
int main(int argc, char** argv){ //MUST BE STARTED WITH ARGV OF 3 or more
	int size = atoi(argv[1]);
	int stop = 1;
	int option=100; //Shoot or move or stop, set to 100 as random
	int direction; //random to start

	int again =1;

	Game* game = new Game(size);
	while (again == 1 || again ==2){
		if(again == 1){
				game->set_board(); //Fills array with event numbers and assigns to warning
			}
		int option =1;
		while (option !=0 && game->get_is_alive()==true&& game->get_win()==false){
			if(game->check_is_alive() == false){
				game->print_board();
				cout<<endl;
				game->print_adventurer_board();		
				break;
			}
			game->print_nearby_event();
			game->print_board();
			cout<<endl;
			game->print_adventurer_board();
			cout<<"Press 1 to move, Press 2 to shoot arrow, Press 0 to stop"<<endl;
			cin>> option;
			if (option==1){
				cout<<"Press 1 to move North"<<endl;
				cout<<"Press 2 to move South"<<endl;
				cout<<"Press 3 to move West"<<endl;
				cout<<"Press 4 to move East"<<endl;
				cin>>direction;
				if(direction ==1){
					game->move_adventurer(1);  //North
				}
				else if(direction ==2){
					game->move_adventurer(2); //South
				}
				else if(direction ==3){
					game->move_adventurer(3); //West
				}
				else if(direction ==4){
					game->move_adventurer(4); //East

				}
				else{
					cout<<"Not an option"<<endl;
				}
				game->run_event();
			}

			else if (option==2){
				cout<<"Press 1 to shoot North"<<endl;
				cout<<"Press 2 to shoot South"<<endl;
				cout<<"Press 3 to shoot West"<<endl;
				cout<<"Press 4 to shoot East"<<endl;
				cin>>direction;
				if(direction ==1){
					game->shoot_arrow(1);
				}
				else if(direction ==2){		
					game->shoot_arrow(2);
				}
				else if(direction ==3){			
					game->shoot_arrow(3);
				}
				else if(direction ==4){
					game->shoot_arrow(4);
				}
				else{
					cout<<"Not an option"<<endl;
				}			

			}

			cout<<endl;
			cout<<endl;
			cout<<endl;
		}
		cout<<"Play again? Press 1 for New Configuration, press 2 for Same Configuration, press 3 to stop"<<endl;
		cin>>again;
		if (again==1){
			delete game;
			Game* game = new Game(size);
		}
		else if (again==2){
			game->game_reset();
			
		}
		else{	
			delete game;
		}
	}

}

//Get program to run again, maybe try to use pointers? Might have a problem with deleting
