#include "gameFunctions.h"
/*
a function that adds the card to the player's winning pile by calling insertFrontCard_LList
input: a player and a specific card
output: cardswon accumulates based on how many times the function is run
special case: Also marks the card as taken ('0').
*/
void addCardToPlayer(Player* thePlayer, Card* theCard)
{
  thePlayer->cardsWon +=1;
  
  insertFrontCard_LList(&thePlayer->winPile, theCard);

  theCard->value ='0';
}

/*
helper function that calculates the coordinates of the index
input: 2 characters that stands for the rows and columns
output: the returned calculated coordinates
//reference: https://www2.cs.sfu.ca/CourseCentral/127/alavergn/Labs/3/Lab3.html
*/
int calculate_coordinate(char row, char col){

  int x = col - 'a';
  int y = row - '0';

  return x + y * 13;
}

/*
a function that checks if the user choice is valid:
input: the deck, player and two characters
output: if any of the choices are invalid, report that and return false.
*/
bool checkPlayerInput(Deck* theDeck, Player* thePlayer, char row, char col)
{
    if(row < '0' || row > '3')
    {
      printf("\nError: The card you picked has invalid number index(es)\n");
      return false; 
    }

    if(col<97 || col>109)
    {
      printf("\nError: The card you picked has invalid alphabet index(es)\n");
      return false;
    }

    if(theDeck->cards[calculate_coordinate(row, col)].value == '0')
    {
      printf("\nError: The card you picked is already taken.\n");
      return false;
    }
  
  return true;
}
/*
helper function that takes in the input. 
input: the deck, player, 2 characters to represent the rows and columns and a turn number. 
output: new values for the rows and cols
special case: will constantly ask for input until correct input is given with do while loop
*/
void input(Deck* theDeck, Player* thePlayer, char* row, char* col, int turn)
{ 
  
  do{
    if (turn == 1){
      printf("Pick the first card you want to turn (e.g., 2 a) then press enter: ");
    }
    if (turn ==2)
    {
      printf("\nPick the second card you want to turn (e.g., 2 b) then press enter: ");
    }
    char input[10];
    fgets(input, 10 , stdin);
    sscanf(input, "%c %c", row, col);
  }while (!checkPlayerInput(theDeck, thePlayer, *row, *col));
  
}
/*
simple helper function to find the card.
input: the deck and two character
output: returns the found card based on the row and col.
note: makes the code appear more neat. 
*/
Card* findCard(Deck* theDeck, char row, char col) 
{
  return &theDeck->cards[calculate_coordinate(row,col)];
}

/*
function that checks if there is a match based on many conditions
input: the select deck and the player
output:  if the two choices are the same return false. if there is a match, return true; otherwise, return false.
*/
bool checkForMatch(Deck* theDeck, Player* thePlayer,
char r1, char c1, char r2, char c2)
{
  Card *firstCard = findCard(theDeck,r1,c1);
  Card *secondCard = findCard(theDeck, r2, c2);

  // Check if cards are identical
  if (firstCard->value == secondCard->value && firstCard->suit == secondCard->suit)
  {
    printf("\nError: Both cards are the same.\n");
    return false;
  }

  if(firstCard->value == secondCard->value)
  {
    return true;
  }
  else{
    return false;
  }
}

/*
a function that checks if the game has a winner
input: the Deck
output: returns true or false depending on whether the deck is filled with '0' or not
*/
bool checkForWinner(const Deck* theDeck)
{
 for(int i=0; i < NUM_OF_CARDS_IN_DECK; i++) 
 {
   if(theDeck->cards[i].value != '0')
   {
     return false;
   }
 }

  return true;
}