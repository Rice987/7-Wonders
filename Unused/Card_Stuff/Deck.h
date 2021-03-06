/*Deck.h*/
#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "Card.h"
using namespace std;

class Deck : public Card{
public:
	Deck(); //does absolutely nothing, for now
	Deck(int); //instantiates n cards into deck
	int dealCard(); //passes out a card
	void shuffle(); //shuffle!
};

Deck::Deck() {}

Deck::Deck(int n) { 
	srand(time(0)); //seed for shuffle

	for (int i = 0; i < n; ++i) {
		addCard(i);
	}
	shuffle();
}

int Deck::dealCard() {
	int ID = cards[0];

	cards.erase(cards.begin()); //destroys first cell since card is being passed out (REMINDER: empty checking)

	return ID;
}

void Deck::shuffle() {
	random_shuffle(cards.begin(), cards.end()); //ah, algorithms

	return;
}

#endif