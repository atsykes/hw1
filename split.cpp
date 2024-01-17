/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"


/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // Current traverses through the nodes
  Node* current = in;
  if (!current) {return;}
  else
  {
    // Head recursion, goes to the end of the Linked List and then does work
    split(current->next, odds, evens);
    //Evens
    if ((current->value % 2) == 0)
    {
      // If Evens is empty, update next pointer to null and add node to evens
      if (!evens) 
      {
        evens = current;
        evens->next = nullptr;
      }
      // If not empty, add this node to the front of the evens list
      else 
      {
        Node* temporary = evens;
        evens = current;
        evens->next = temporary;
      }
    }
    //Odds
    else
    {
      // If Odds is empty, update next pointer to null and add node to odds
      if (!odds) 
      {
        odds = current;
        odds->next = nullptr;
      }
      // If not empty, add this node to the front of the odds list
      else 
      {
        Node* temporary = odds;
        odds = current;
        odds->next = temporary;
      }
    }
  }
  in = nullptr;
}

/* If you needed a helper function, write it here */
