#pragma once
#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;

	/*
	These are the only functions you'll need to code
	for this class. See the implementations of the two
	functions above to get an idea of how to proceed.
	*/
	string get_english_suit() const;
	//string get_english_rank() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;
	double get_value()const;
	void print() const;
	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;
	bool operator ==(Card card2) const;

private:
	int suit;
	int rank;
	double value;
};

class Hand {
public:
	// A vector of Cards
	Hand();
	void draw();
	double sum() const;
	vector<Card> get_cards()const;
private:
	vector<Card> hand;
};


class Player {
public:
	// Constructor. 
	//    Assigns initial amount of money
	Player(int m);
	bool minus(int m);
	int get_money()const;
	void plus(int m);
	void print_cards() const;
	Hand get_hand();
	void add_card();
private:
	int money;
	Hand cards;
};

#endif
