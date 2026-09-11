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

void printList(Node* list){
  if(list == NULL){
    cout << "null";
    return;
  }

  cout << list->value << endl;
  printList(list->next);
}

void deleteList(Node* list){
  if(list == NULL){
    return;
  }

  deleteList(list->next);
  delete list;
}
int main(int argc, char* argv[])
{
  Node* list = new Node(0, NULL);
  list->next = new Node(1, NULL);
  list->next->next = new Node(2, NULL);
  list->next->next->next = new Node(3, NULL);

  Node* odds = NULL;
  Node* evens = NULL;

  split(list, odds, evens);

  cout << "Odd list" << endl;
  printList(odds);
  cout << endl;

  cout << "Even list" << endl;
  printList(evens);
  cout << endl;

  cout << "Current list" << endl;
  printList(list);
  cout << endl; 

  deleteList(odds);
  deleteList(evens);
  
  return 0;
}
