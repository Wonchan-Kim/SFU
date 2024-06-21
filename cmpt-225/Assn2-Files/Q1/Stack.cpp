/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Wonchan Kim & Jaclyn Sunardi
 * Date: June 4, 2024
 */
#include "Stack.h"

// Default constructor
// Description: Default Stack class constructor
// Stacknode pointer poiting tail and head should be initizalized to nullptr, and count should be initizalized to 0.
Stack::Stack() {
    this->count = 0;
    head = nullptr;
    top = nullptr;
}
// Default destructor
// Description: Pop all the elements stored in the Stack
Stack::~Stack() {
    while(!this->isEmpty())
        this->pop();
}
// push method
// Description: push the element through the stack
// Postcondition: New element inserted, number of elements in Stack increased by 1. Top points to the new element
// Time Complexity: O(n)
// top of the stack should be at the back of the LL
void Stack::push(const int& data){
    //top of the stack doesnt move, which means new nodes should be inserted in the head

    //create new node
    StackNode* newNode = new StackNode();
    newNode->data = data;
    newNode->next = nullptr;

    //check if the stack is empty
    if(this->isEmpty()){
        //insert in the head
        head = newNode;
        top = newNode;
        count++;
    }
    else {
        //update the top
        top->next = newNode;
        top = top -> next;
        top -> next = nullptr;
        count++;
    }
}
// pop method
// Description: eliminate the top and renew the top
// Precondition: The stack is not empty
// Postcondition: Top element is removed and new top is the element that was 'under' the top, and the number of elements stored in Stack decreased by 1.
// Time Complexity: O(n)
void Stack::pop() {
    // check precondition
    if(this->isEmpty())
        return;
    // delete a single node if size of stakc is 1
    if(count == 1){
        delete top;
        top = nullptr;
        head = nullptr;
        count--;
    }
    else {
        //temp tracks the next candidate for top
        StackNode* temp = head;
        while(temp->next != top){
            temp = temp->next;
        }
        //update top
        delete top;
        top = temp;
        top->next = nullptr;
    }
    count--;
}
// peek method
// Description: returns the element stored in the top
// PreCondition: The stack should not be empty, returns the error if so.
// Time Complexity: O(1)
int& Stack::peek() const{
    //peek can not return if stack is empty
    //throw error
    if(this->isEmpty()){
        throw std::runtime_error("Stack is empty, peek method is not in appropriate usage.");
    }
    //return the data stored in top
    return top->data;
}
// isEmpty method
// Description: check is current stack is empty
// Time Complexcity: O(1)
bool Stack::isEmpty() const{
    if (head == nullptr)
        return true;
    return false;
}
// pop all method
// Description: remove all the elements in the stack
// Postcondition: no elements are left in stack
// Time Copmlexity: O(n^2)
void Stack::pop_all() {
    while(!this->isEmpty()){
        this->pop();
    }
}
// getElementCount method
// Description: return how many elements are stored in the stack
int Stack::getElementCount() const {
    return count;
}