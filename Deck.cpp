//***************************************************************************
// File name:  Deck.cpp
// Author:     Cooper DeLay
// Date:       3/10/18
// Class:      CS250
// Assignment: Card
// Purpose:    Implements constructers and functions of class Deck
//***************************************************************************

#include "stdafx.h"
#include "Deck.h"




Deck::Deck ()
{
  const int RAND_SEED = 2;

  for (int i = 0; i < MAX_CARDS_IN_DECK; i++)
  {
    macDeckOfCards[i] = i;
    
  }
  mTopCardIndex = MAX_CARDS_IN_DECK;
  srand (RAND_SEED);
}

void Deck::shuffle ()
{
  int randomIndex;

  for (int cardIndex = MAX_CARDS_IN_DECK - 1; cardIndex > -1; cardIndex--)
  {
    randomIndex = rand() % (cardIndex);

    macDeckOfCards[cardIndex] = randomIndex;
    macDeckOfCards[randomIndex] = cardIndex;
  }
}

Card Deck::deal ()
{
  return Card ();
}

int Deck::cardsLeft () const
{
  return 0;
}

void Deck::testPrintt () const
{
  for (int i = 0; i < MAX_CARDS_IN_DECK - 1; i++)
  {
    macDeckOfCards[i].testPrint;
    if (i % 13 == 0)
    {
      std::cout << std::endl;
    }
  }
}
