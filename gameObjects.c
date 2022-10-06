#include "gameObjects.h"

/*
function that prints the special symbols of cards
input: card and a bool value
output: the special symbols based on whether the card is a
Spade, Heart, Club or Diamond or it will print a box if bool is false.
special case: if there is no card then it will just print spaces to keep the cards looking neat.
*/
void printcard(Card card, bool faceUp)
{
  if(card.value == '0')
  {
    printf("  ");
    
  }

  else if(faceUp ==true)
  {
    printf("%c",card.value);
    switch(card.suit) 
    {
      case Spades:
        printf("\u2660");
        break;
      case Hearts:
        printf("\u2661");
        break;
      case Clubs:
        printf("\u2663");
        break;
      case Diamonds:
        printf("\u25c7");
        break;
    }
  }
  else
  {
    printf("?\u218C");
  }
  
  printf(" ");
}
/*
swap function that swaps cards
input: two different cards
output: the swapped cards
*/
void swapcards(Card *card1 ,Card *card2 )
{
  Card temp;

  temp = *card1;
  *card1 = *card2;
  *card2 = temp;
}

/*
a function that initializes all the fields of a Deck.
input: the deck and the brand name
output: returns the initialized deck and stores them within data
*/
void initializeDeck(Deck* theDeck, char* brandName)
{
  // Initialize cards in deck (malloc)
  theDeck->brand = brandName; 

  for (int i = 0; i < 4; i++)
  {
    
    Suit suit;

    switch(i)
    {
      case 0:
        suit = Spades;
        break;
      case 1:
        suit = Hearts;
        break;
      case 2:
        suit = Clubs;
        break;
      case 3:
        suit = Diamonds;
        break;
    }

    for(int j = 0; j < 13; j++)
    {
      char value;
      switch(j)
      {
        case 0:
          value = 'A';
          break;
        case 9:
          value = 'T';
          break;
        case 10:
          value = 'J';
          break;
        case 11:
          value = 'Q';
          break;
        case 12:
          value = 'K';
          break;
        default:
          value = j+49;

      }

      // Make a card
      Card card;
      card.suit = suit;

      // Store the card in the correct position
      card.value = value;

      theDeck->cards[j + i * 13]=card;
    }
  }
  
}

/*
Function that shuffles the deck
input: a deck
output: the shuffled deck based on rand()
special note: utilizes the swap card function.
*/
void shuffleDeck(Deck* theDeck)
{
  for(size_t i = 0; i < NUM_OF_CARDS_IN_DECK - 1; i++) 
  { 

    size_t r = i + rand() / ( RAND_MAX / (NUM_OF_CARDS_IN_DECK-i)+1); 
    swapcards(&theDeck->cards[i], &theDeck->cards[r]); 
    
  } 
}
/*
a function that prints the content of a Deck.
input: accepts a second bool parameter:
output:if true, print face up, if false, print face down.if the card is won by a player, leave it blank.
*/
void printDeck(const Deck* theDeck, bool faceUp)
{
  if(theDeck == NULL)
  {
    return;
  }

  if(faceUp==true)
  {
    printf("Brand of Deck: %s\n", theDeck->brand);
  }

  printf("   a  b  c  d  e  f  g  h  i  j  k  l  m");

  for(int i=0; i < NUM_OF_CARDS_IN_DECK; i++)
  {
    if(i == 0 || i==13 || i ==26 || i==39 || i==52)
    { 
      printf("\n");
      printf("%d ",i/13);
    }
    
    printcard(theDeck->cards[i], faceUp);
  }
}

/*
a function that initializes all the fields of a Player.
input: a player and the players name
output: initializes a winpile, their name and the number of cards won.
*/
void initializePlayer(Player* thePlayer, char* theName)
{

  thePlayer->winPile = *createCard_LList();
  thePlayer->name = theName;
  thePlayer->cardsWon = 0;
}

/*
a function clears the winning pile of the player by calling clearCard_LList
input: a player
output: the freed and cleared memory
*/
void clearPlayer(Player* thePlayer)
{
  clearCard_LList(&thePlayer->winPile);
}
