/*Program Filename: Zoo_tycoon
 * Author: Dennis Li
 * Date: 2/20/17
 * Description: This program runs the game of zoo tycoon where a player starts with 100000 and is able to by animals to make a profit.
 * Input:User input for choices
 * Output:Revenue of th zoo
 */


#include<iostream>
#include<string>
#include<cstdlib>
#include"animal.hpp"
#include"monkey.hpp"
#include"sloth.hpp"
#include"sea_otter.hpp"
#include"game.hpp"
using namespace std;
void sick_animal(Game&);
void babies(Game&);

/*Function: Main
 * Description: Main function for zoo tycoon
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Uses class game to run game
 */

int main(){
	Game game;
	int animal_type; //1 = monkey, 2 = sloth, 3 = sea otter
	int buy_num_animals;
	int special_event;
	int prompt;
	int again;
	srand(time(NULL));

	cout<<"Welcome to zoo tycoon!"<<endl;
	while(game.get_bankrupt()==false){

		//Buy animal
		cout<<"Day: "<<game.get_days()<<endl;
		cout<<"Money: "<<game.get_money()<<endl;
		cout<<endl;
		cout<<" Would you like to buy an animal? "<<endl;
		cout<<" Press 1 for Monkey, 2 for Sloth, 3 for Sea Otter"<<endl;
		cin>>animal_type;
		cout<<" How Many? (0-2)"<<endl;
		cin>>buy_num_animals;

		for(int i=0;i<buy_num_animals;i++){
			if(animal_type==1){
				game.add_monkey();
				game.get_money()= game.get_money() - (game.get_specific_monkey(0)).get_cost(); //Set to 0 because the cost is constant

			}
			if(animal_type==2){
				game.add_sloth();
				game.get_money()= game.get_money() - (game.get_specific_sloth(0)).get_cost(); //Set to 0 because the cost is constant

			}
			if(animal_type==3){
				game.add_sea_otter();
				game.get_money()= game.get_money() - (game.get_specific_sea_otter(0)).get_cost(); //Set to 0 because the cost is constant

			}
		}		
		cout<<"Money after buying animals: "<<game.get_money()<<endl;
		cout<<endl;
		cout<<endl;

		//Display Animals
		cout<<"Number of Monkeys: "<<game.get_num_monkeys()<<endl;
		game.display_monkeys();
		cout<<"Number of Sloths: "<<game.get_num_sloths()<<endl;
		game.display_sloths();
		cout<<"Number of Sea Otters "<<game.get_num_sea_otters()<<endl;
		game.display_sea_otters();

	
		cout<<endl;
		cout<<endl;	
		cout<<endl;
		cout<<endl;


		//Special Event
		cout<<"Press 1 to proceed to special event(random)"<<endl;
		cin.ignore();
		cin>>prompt;
		special_event=(rand()%4)+1;
		if (special_event==1){
			sick_animal(game);
		}


		else if (special_event==2){

			babies(game);

		}
		
		   else if (special_event==3){
		   cout<<"Boom in Zoo Attendance, Each monkey generates an extra bonus revenue of 250-500 dollars"<<endl;
		   }
		   else if (special_event==4){
		   cout<<"No special event has occured"<<endl;
		   }

		//Calculate Food Cost
		cout<<endl;
		cout<<"Press 1 to proceed to subtract food cost"<<endl;
		cin.ignore();
		cin>>prompt;
		game.subtract_food_cost();
		cout<<"Money after food cost: "<<game.get_money()<<endl;
		cout<<endl;


		//Calculate Revenue
		cout<<endl;
		cout<<"Press 1 to proceed to recieve revenue"<<endl;
		cin.ignore();
		cin>>prompt;
		if (special_event==3){ //Refers back to special event 3
		game.recieve_revenue(2);// revenue with bonus
		}
		else if (special_event!=3){
		game.recieve_revenue(1);
		}
		cout<<"Money after recieving revenue: "<<game.get_money()<<endl;
		cout<<endl;



		//Increment day and ask user to stop
		cout<<"Press 1 to continue to next day, or press 0 to quit"<<endl;
		cin.ignore();
		cin>>again;

		if(again==0){
			cout<<"Thanks for playing"<<endl;
			game.set_bankrupt(true);
		}
		if(game.get_money()<0){
			cout<<"You went Bankrupt!"<<endl;
			game.set_bankrupt(true);
		}
		game.increment_day();
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
}


/*Function: sick animal
 * Description: Chooses an animal to make sick and lets user decide whether to save the animal or let it die
 * Parameters: Game
 * Pre-conditions: Game used for playing
 * Post-conditions: Dead animal or lost money to save it
 */

void sick_animal(Game& game){
	int animal_type;
	int specific_animal;
	int pay_fee;
	int sick_cost;
	animal_type = (rand()%3)+1;
	if(animal_type==1 &&game.get_num_monkeys()>0){
		cout<<"A monkey has become sick"<<endl;
		cout<<"Press 1 to heal animal (Pay half of original) or press 2 to let it die"<<endl;
		cin>>pay_fee;
		if (pay_fee==1){
			game.get_money()=game.get_money()-7500;
			cout<<"Money after sick animals: "<<game.get_money()<<endl;
		}
		else if(pay_fee=2){
			cout<<"The animal died"<<endl;
			specific_animal = (rand()%game.get_num_monkeys());
			game.remove_monkey(specific_animal);
		}	
	}
	else if (animal_type==2 &&game.get_num_sloths()>0){
		cout<<"A sloth has become sick"<<endl;
		cout<<"Press 1 to heal animal (Pay half of original) or press 2 to let it die"<<endl;
		cin>>pay_fee;
		if (pay_fee==1){
			game.get_money()=game.get_money()-2500;
			cout<<"Money after sick animals: "<<game.get_money()<<endl;
		}
		else if(pay_fee=2){
			cout<<"The animal died"<<endl;
			specific_animal = (rand()%game.get_num_sloths());
			game.remove_sloth(specific_animal);

		}	
	}
	else if (animal_type==3&&game.get_num_sea_otters()>0){
		cout<<"A sea otter has become sick"<<endl;
		cout<<"Press 1 to heal animal (Pay half of original) or press 2 to let it die"<<endl;
		cin>>pay_fee;
		if (pay_fee==1){
			game.get_money()=game.get_money()-100;
			cout<<"Money after sick animals: "<<game.get_money()<<endl;

		}
		else if(pay_fee=2){
			cout<<"The animal died"<<endl;
			specific_animal = (rand()%game.get_num_sea_otters());
			game.remove_sea_otter(specific_animal);

		}	
	}
	else{
		cout<<"No special event has occured"<<endl;	
	}
}


/*Function: babies
 * Description: Chooses an adult animal to choose to give birth
 * Parameters: Game
 * Pre-conditions: Game used for playing
 * Post-conditions: Add animal to array 
 */
void babies(Game& game){
	int animal_type;
	animal_type = (rand()%3)+1;
	int specific_animal;
	if (animal_type==1&&game.get_num_monkeys()>0){   //Have a baby if there is parent in array
		specific_animal = (rand()%game.get_num_monkeys());
		if( (game.get_specific_monkey((specific_animal)).get_age())>=1095){ //Have a baby if the other monkey is an adult
			cout<<"A monkey had a baby!"<<endl;
			cout<<endl;		
			game.get_specific_monkey((specific_animal)).add_babies(1);
			game.add_monkey();
			game.get_specific_monkey((game.get_num_monkeys())-1).set_age(0);

		}
		else{
			cout<<"No special event has occured"<< endl;
		}	

	}	
	else if (animal_type==2&&game.get_num_sloths()>0){

		specific_animal = (rand()%game.get_num_sloths());
		if( (game.get_specific_sloth((specific_animal)).get_age())>=1095){
			cout<<"A sloth had 3 babie!"<<endl;
			cout<<endl;	
			for(int i=0; i<3; i++){
				game.get_specific_sloth((specific_animal)).add_babies(1);
				game.add_sloth();
				game.get_specific_sloth((game.get_num_sloths())-1).set_age(0);
			}
		}
		else{
			cout<<"No special event has occured"<< endl;
		}	
	}	
	else if (animal_type==3&&game.get_num_sea_otters()>0){

		specific_animal = (rand()%game.get_num_sea_otters());
		if( (game.get_specific_sea_otter((specific_animal)).get_age())>=1095){
			cout<<"A sea otter had 2 babies!"<<endl;	
			cout<<endl;	
			for(int i=0; i<2; i++){
				game.get_specific_sea_otter((specific_animal)).add_babies(1);
				game.add_sea_otter();
				game.get_specific_sea_otter((game.get_num_sea_otters())-1).set_age(0);
			}
		}
		else{
			cout<<"No special event has occured"<< endl;
		}	
	}
	else{
		cout<<"No special event has occured"<< endl;
	}	
}


