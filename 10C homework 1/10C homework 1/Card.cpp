#include "Card.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Card::Card()
{
	srand((unsigned)time(0));
	int r_suit = rand() % 4;
	int r_rank = rand() % 10;
	suit = r_suit;
	rank = r_rank;
}
string Card::get_spanish_rank() const
{
	if (rank == 0)
		return "As";
	else if (rank == 1)
		return "Dos";
	else if (rank == 2)
		return "Tres";
	else if (rank == 3)
		return "Cuatro";
	else if (rank == 4)
		return "Cinco";
	else if (rank == 5)
		return "Seis";
	else if (rank == 6)
		return "Siete";
	else if (rank == 7)
		return "Sota";
	else if (rank == 8)
		return "Caballo";
	else if (rank == 9)
		return "Rey";
}
string Card::get_spanish_suit() const
{
	if (suit == 0)
		return "Oros";
	else if (suit == 1)
		return "Copas";
	else if (suit == 2)
		return "Espadas";
	else if (suit == 3)
		return "Bastos";


}
int Card::get_rank() const
{
	int temp;
	if (rank <= 6)
	{
		temp = rank + 1;
		return temp;
	}
	else if (rank == 7)
		return 10;
	else if (rank == 8)
		return 11;
	else if (rank == 9)
		return 12;
}
string Card::get_english_suit()const
{
	if (suit == 0)
		return "Golds";
	else if (suit == 1)
		return "Cups";
	else if (suit == 2)
		return "Swords";
	else if (suit == 3)
		return "Clubs";
}
bool Card::operator<(Card card2) const
{
	if (rank < card2.rank)
		return true;
	else
		return false;
}
bool Card::operator==(Card card2) const
{
	if (rank == card2.rank)
		return true;
	else
		return false;
}
double Card::get_value()const
{
	double temp;
	if (rank <= 6)
	{
		temp = rank + 1.0;
		return temp;
	}
	else
		return 0.5;
}
void Card::print()const
{
	cout << get_spanish_rank() << " de " << get_spanish_suit() << endl;
}
Hand::Hand()
{
	hand.push_back(Card());
}
void Hand::draw()
{
	hand.push_back(Card());
}
double Hand::sum()const
{
	double total;
	for (auto x : hand)
		total += x.get_value();
	return total;
}
vector<Card> Hand::get_cards()const
{
	return hand;
}
Player::Player(int m)
{
	money = m;
	cards = Hand();
}
int Player::get_money()const
{
	return money;
}
bool Player::minus(int m)
{
	if (m <= money)
	{
		money = money - m;
		return true;
	}
	else
		return false;
}
void Player::plus(int m)
{
	money += m;
}
void Player::print_cards()const
{
	for (auto x : cards.get_cards())
	{
		x.print();
	}
}
Hand Player::get_hand()
{
	return cards;
}
void Player::add_card()
{
	cards.draw();
}