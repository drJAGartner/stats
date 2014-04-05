/******************************
 * dice.cc				*
 * variable faced dice object *
 * v1.0 - April 1, 2014		*
 *****************************/

#include "./card.h"
#include <iostream>


card::card(unsigned int orderInDeck, bool isVerbose)
: bVerboseCards(isVerbose)
{
	if(orderInDeck>51)
	{
		suit = JOKER;
		rank = 0;
		
	} else {
		int sCounter=0;
		while(orderInDeck>12)
		{
			sCounter++;
			orderInDeck-=13;
		}
		suit = static_cast<t_cardSuit>(sCounter);
		rank = orderInDeck;
	}
	if(bVerboseCards) cout << "Create " << this->getStringCard() << endl;

}

card::~card()
{
	if(bVerboseCards) cout << "Deleting " << this->getStringCard() << endl;
}

card::card(const unsigned short &nRank, const unsigned int &nSuit)
{
	if(nSuit>3)
	{
		suit = JOKER;
		rank = 0;
	}
	else{
		if(rank>12)
		{
			suit = JOKER;
			rank = 0;
		} else {
			
			suit = static_cast<t_cardSuit>(nSuit);
			rank = nRank;
		}
	}
	
}

string card::getStringCard()
{
	if(suit==JOKER) return "Joker";
	
	
	string strRankArr[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	
	string strRetVal = strRankArr[rank];
	
	
	if(suit==HEART) strRetVal.append(" of Hearts");
	if(suit==DIAMOND) strRetVal.append(" of Diamonds");
	if(suit==CLUB) strRetVal.append(" of Clubs");
	if(suit==SPADE) strRetVal.append(" of Spades");
	
	return strRetVal;
}

