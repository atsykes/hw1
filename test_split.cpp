/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  Node node6(6, nullptr);
  Node node5(5, &node6);
  Node node4(4, &node5);
  Node node3(3, &node4);
  Node node2(2, &node3);
  Node node1(1, &node2);

  Node* is = &node1;
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(is, odds, evens);

  cout << "Odds:" << endl;
  while(odds)
  {
    cout << odds->value;
    odds = odds->next;
  }
  cout <<"\nEvens:" << endl;
  while(evens)
  {
    cout << evens->value;
    evens = evens->next;
  }


  return 0;
}
