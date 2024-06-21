/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Wonchan Kim & Jaclyn Sunardi
 * Date: June 2,2024
 */
#include <iostream>

using std::endl;
using std::cin;
using std::cout;
class Stack {

  private:
    
    // Description:  Nodes for a singly-linked list - Do not modify!
    class StackNode {
      public:
        int data;
        StackNode * next;
    };
        
/* Put your code here! */       
    StackNode* top; //points to the tail of the SHSL
    StackNode* head; //points to the head of the SHSL
    int count; // count how many nodes are stored in the SHSL


  public:
    

/* Put your code here! */
  // Default constructor
  // Description: Default Stack class constructor
  // Stacknode pointer poiting tail and head should be initizalized to nullptr, and count should be initizalized to 0.
  Stack(); 
  
  // Default destructor
  // Description: Pop all the elements stored in the Stack
  ~Stack();

  // peek method
  // Description: returns the element stored in the top
  // PreCondition: The stack should not be empty, returns the error if so.
  // Time Complexity: O(1)
  int& peek() const;

  // pop method
  // Description: eliminate the top and renew the top
  // Precondition: The stack is not empty
  // Postcondition: Top element is removed and new top is the element that was 'under' the top, and the number of elements stored in Stack decreased by 1.
  // Time Complexity: O(n)
  void pop();

  // push method
  // Description: push the element through the stack
  // Postcondition: New element inserted, number of elements in Stack increased by 1. Top points to the new element
  // Time Complexity: O(n)
  void push(const int& data);

  // isEmpty method
  // Description: check is current stack is empty
  // Time Complexcity: O(1)
  bool isEmpty() const;
  
  // pop all method
  // Description: remove all the elements in the stack
  // Postcondition: no elements are left in stack
  // Time Copmlexity: O(n^2)
  void pop_all();

  // getElementCount method
  // Description: return how many elements are stored in the stack
  int getElementCount() const;
};
