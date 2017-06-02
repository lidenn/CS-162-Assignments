/*Program Filename: Game.hpp
 * Author:Dennis
 * Date:2/20/17
 * Description: Game class's data and methods
 * Input:none
 * Output:none
 */
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game{
	private:
		int days;
		float money;
		float daily_food_cost;
		bool bankrupt;

		Monkey * total_monkeys;
		Sloth * total_sloths;
		Sea_otter * total_sea_otters;
		int num_monkeys;
		int num_sloths;
		int num_sea_otters;

	public:
		Game();
		~Game();
		int &get_days();
		float &get_money();
		float get_daily_food_cost();
		bool get_bankrupt();
		void set_bankrupt(bool x);

		//Monkey functions
		Monkey &get_specific_monkey(int x);
		void add_monkey();
		void remove_monkey(int removed);
		void display_monkeys();
		int get_num_monkeys();

		//Sloth functions
		Sloth &get_specific_sloth(int x);
		void add_sloth();
		void remove_sloth(int removed);
		void display_sloths();
		int get_num_sloths();

		//Sea Otter Functions
		Sea_otter &get_specific_sea_otter(int x);
		void add_sea_otter();
		void remove_sea_otter(int removed);
		void display_sea_otters();
		int get_num_sea_otters();

		//Game functions
		void recieve_revenue(int bonus);
		void subtract_food_cost();
		void increment_day();

};
#endif

