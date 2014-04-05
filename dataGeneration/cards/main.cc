/************************************
* gambit's game                     *
* this is an example of how to use  *
* the deckOfCards and card classes. *
************************************/


#include "./deckOfCards.h"
#include <iostream>

using namespace std;
int main()
{
	cout << "***Create New Deck of Cards***" << endl;
	deckOfCards *myDeck = new deckOfCards();
	
	cout << endl << "Input a number of shuffles: ";
	unsigned short nShuff=0;
	cin >> nShuff;
	for(int i=0; i<nShuff; i++)
	{
		cout << "Shuffle " << i+1 << endl;
		myDeck->shuffle();
	}
	
	cout << "***Deal a card to me***" << endl;
	card* myCard = myDeck->dealFromTop();
	card* gambitsCard = myDeck->dealFromBottom();
	
	cout << "My card is a " << myCard->getStringCard() << endl;
	cout << "Gambit's card is a " << gambitsCard->getStringCard() << endl;
	
	cout << "***Delete cards***" << endl;
	delete myCard;
	delete gambitsCard;
	cout << "***Delete rest of deck***" << endl;
	delete myDeck;
}