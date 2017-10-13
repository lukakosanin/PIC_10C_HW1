#include "Card.h"
#include <iostream>
#include <string>


int main()
{
	int end = 900;
	int initial;
	int bet;
	double max_sum = 7.5;
	double dealer_sum = 6.5;
	int ans;
	std::cout << "Please enter the amount of money you wish to start with: ";
	std::cin >> initial;
	Player p1 = Player(initial);
	Player dealer = Player(end);

	while (p1.get_money() > 0 && dealer.get_money()>0)
	{
		std::cout << "You have " << p1.get_money() << " dollars. How much do you want to bet? ";
		std::cin >> bet;
		std::cout << "Your cards are: ";
		p1.print_cards();
		std::cout << "Draw a card? 0 for yes, 1 for no: ";
		cin >> ans;
		while ((ans == 0 || ans == 0) && p1.get_hand().sum() <= max_sum)
		{
			p1.add_card();
			std::cout << "Your cards are: " << endl;
			p1.print_cards();
			std::cout << "Draw a card? 0 for yes, 1 for no: ";
			cin >> ans;
		}
		while (dealer.get_hand().sum() <= dealer_sum)
		{
			dealer.add_card();
		}
		if (p1.get_hand().sum()>max_sum&&dealer.get_hand().sum()>max_sum)
		{
			p1.minus(bet);
		}
		else if (p1.get_hand().sum() > max_sum || dealer.get_hand().sum() > max_sum)
		{
			if (p1.get_hand().sum() < dealer.get_hand().sum())
			{
				p1.plus(bet);
				dealer.minus(bet);
			}
			else
			{
				p1.minus(bet);
			}
		}
		else
		{
			if (p1.get_hand().sum() > dealer.get_hand().sum())
			{
				p1.plus(bet);
				dealer.minus(bet);
			}
			else
			{
				p1.minus(bet);
			}
		}
	}
	if (p1.get_money() <= 0)
	{
		std::cout << "You Lose!";
	}
	else
	{
		std::cout << "You win! You have " << p1.get_money() << "dollars.";
	}
	return 0;

}

