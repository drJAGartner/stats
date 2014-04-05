#include "./deckofCards.h"
minstd_rand0 *deckOfCards::rNum;
int deckOfCards::nDeckInst=0;

deckOfCards::deckOfCards()
{
	for(int i=0; i<52; i++)
	{
		theDeck.push_back(new card(i));
	}
	
	if(rNum==NULL)
	{
		rNum = new minstd_rand0(time(NULL));
	}
	nDeckInst++;
}

deckOfCards::~deckOfCards()
{
	while(!theDeck.empty())
	{
		delete theDeck.back();
		theDeck.pop_back();
	}
	
	delete rNum;
}

void deckOfCards::shuffle()
{
	deque<card*> leftStack;
	deque<card*> rightStack;
	
	for(int i=0; i<26; i++)
	{
		leftStack.push_back(theDeck.front());
		theDeck.pop_front();
		
		rightStack.push_front(theDeck.back());
		theDeck.pop_back();
	}
	
	while(!leftStack.empty()||!rightStack.empty())
	{
		if(!leftStack.empty())
		{
			theDeck.push_front(leftStack.back());
			leftStack.pop_back();
			if(((*rNum)()%3==0)&&(!leftStack.empty()))
			{
				//randomly include 2nd card on 1/3 basis
				theDeck.push_front(leftStack.back());
				leftStack.pop_back();
			}
		}
		
		if(!rightStack.empty())
		{
			theDeck.push_front(rightStack.back());
			rightStack.pop_back();
			if(((*rNum)()%3==0)&&(!rightStack.empty()))
			{
				theDeck.push_front(rightStack.back());
				rightStack.pop_back();
			}
		}
	}
	
	return;
}

card* deckOfCards::dealFromTop()
{
	card* deltCard = theDeck.front();
	theDeck.pop_front();
	return deltCard;
}

card* deckOfCards::dealFromBottom()
{
	card* deltCard = theDeck.back();
	theDeck.pop_back();
	return deltCard;
}
