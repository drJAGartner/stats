// dice object for dice rolling experiments

#ifndef CARD_H
#define CARD_H
#include "./cardSuit.h"
#include <string>

using namespace std;

class card
{
public:
	card(unsigned int orderInDeck, bool isVerbose=false);
	card(const unsigned short&, const unsigned int&);
	~card();
	int getRank() {return rank;}
	int getSuit() {return suit;}
	string getStringCard();
private:
	t_cardSuit suit;
	unsigned short rank;
	bool bVerboseCards;
};

#endif