#include "card_LList.h"

/*
a function that creates a new Card_LList, which is an empty linked list.
input: does not require an input but must be assigned to a variable.
output: the created card linked list
*/
Card_LList* createCard_LList()
{
  Card_LList* cards = malloc(sizeof(Card_LList));

  cards->head = NULL;
  cards->tail = NULL;

  return cards;
}

/*
a function that removes all the nodes from the list that frees the list one by one
input: a list
output: an empty linked list.
*/
void clearCard_LList(Card_LList* theList)
{
  while(theList->head)
  {
    removeFrontCard_LList(theList);
  }
}

/*
a function that checks if the list is empty.
input: a list
output:If it is empty, return true; otherwise return false.
*/
bool isEmptyCard_LList(Card_LList* theList)
{
  if(theList==NULL && theList->head)
  {
    return true;
  }

  return false;
}

/*
a function that inserts the card as a part of a node. encapsulates the inner working of the linked list
input: a list and the specifc card
output: the linked list with a node inserted from the front
*/
void insertFrontCard_LList(Card_LList* theList, Card* theCard)
{
  // 1 - Create new element
  Card_Node* thefront = malloc(sizeof(Card_Node));

  // 2 - Set the "next" element to the current "head"
  thefront->next = theList->head;
  
  // 3 - Set my card value
  thefront->card = theCard;
  
  // 4 - Replace the existing "head" with the new element
  theList->head = thefront;

  if(theList->tail == NULL) 
  {
    theList->tail = thefront;
  }
}

/*
a function that inserts the card to the back as part of a node. Encapsulates the inner working of the linked list
input: a list and the specifc card
output: the linked list with a node inserted from the back
*/
void insertEndCard_LList(Card_LList* theList, Card* theCard)
{
  Card_Node* theEnd = malloc(sizeof(Card_Node));

  theEnd->next = NULL;
  theEnd->card = theCard;

  if(theList->tail != NULL)
  {
    theList->tail->next = theEnd;
  }
  
  theList->tail = theEnd;
  
  if(theList->head == NULL) 
  {
    theList->head = theEnd;
  }
}

/*
a function that removes the front value of the linked list
input: a list
output: the linked list that removed the front item of the linked list
*/
Card* removeFrontCard_LList(Card_LList* theList)
{
  Card_Node* shiftforward = theList->head->next;

  Card_Node *temp;
  
  temp = theList->head;

  Card* card = temp->card;

  if(theList->tail == theList->head) 
  {
    theList->tail = NULL;
  }

  theList->head = shiftforward;

  free(temp);

  return card;
}

/*
a function that removes the end value of the linked list
input: a list
output: the linked list that removed the front item of the linked list
*/
Card* removeEndCard_LList(Card_LList* theList)
{
  Card_Node* toDelLast = theList->head;
  Card_Node* preNode = theList->head;

  if(theList->head == NULL)
  {
    return NULL;
  }

  Card* card = theList->tail->card;

  while(toDelLast != theList->tail)
  {
    preNode = toDelLast;
    toDelLast = toDelLast->next;
  }

  if(preNode != NULL)
  {
    preNode->next = NULL;
  }

  theList->tail = preNode;

  if(preNode == theList->head)
  {
    theList->head = NULL;
  }

  free(toDelLast);
  return card;
}