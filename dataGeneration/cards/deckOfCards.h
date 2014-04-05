// dice object for dice rolling experiments

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "./card.h"
#include <string>
#include <deque>
#include <random>

using namespace std;

class deckOfCards
{
public:
	deckOfCards();
	~deckOfCards();
	void shuffle();
	card* dealFromTop();
	card* dealFromBottom();
private:
	deque<card*> theDeck;
	static int nDeckInst;
	static minstd_rand0* rNum;
};

#endif