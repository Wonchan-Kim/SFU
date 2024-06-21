/* 
 * Queue.cpp - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jaclyn Sunardi and Wonchan Kim
 * Date: June 04 2024
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {
  elements = new int[INITIAL_CAPACITY];
}

// Description: Destructor
Queue::~Queue() {
  delete[] elements;
}

// Description: Copy constructor
Queue::Queue(const Queue& tobeCopied):elementCount(tobeCopied.elementCount), capacity(tobeCopied.capacity),
            frontindex(tobeCopied.frontindex), backindex(tobeCopied.backindex) {
              
              elements = new int[capacity];
              for (unsigned int i = 0; i < capacity; i++) {
                elements[i] = tobeCopied.elements[i];
              }
            }

// Description: Overload Assignment = operator
Queue& Queue::operator=(const Queue& other) {
  if (this != &other) {
    delete[] elements;

    // Copy all data members
    elementCount = other.elementCount;
    capacity = other.capacity;
    frontindex = other.frontindex;
    backindex = other.backindex;

    // Allocate new memory for elements
    elements = new int[capacity];
    for (unsigned int i = 0; i < capacity; i++) {
      elements[i] = other.elements[i];
    }
  }
  return *this;
}

// Description: Resizing 

void Queue::resize(unsigned int newCapacity) {
  // Allocate new memory and copy elements in FIFO order
    int* newElements = new int[newCapacity];
    for (unsigned int i = 0; i < elementCount; ++i) {
        newElements[i] = elements[(frontindex + i) % capacity];
    }

    // Free old memory and update elements pointer, indexes and capacity
    delete[] elements;
    elements = newElements;
    frontindex = 0;
    backindex = elementCount;
    capacity = newCapacity;
}


// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
  // Expand if needed
  if (elementCount == capacity) {
    resize(2*capacity);
  }
  // Insert element at the back and update index
  elements[backindex] = newElement;
  backindex = (backindex + 1) % capacity;
  elementCount++;
} 



// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
  // If queue is empty, do nothing
  if (elementCount == 0) {
    return;
  }

  // Move front index forward
  frontindex = (frontindex + 1) % capacity;
  elementCount--;
  // Shrink array if needed 
  if (elementCount > 0 && elementCount <= capacity / 4 && capacity > INITIAL_CAPACITY) {
    resize(capacity / 2);
  }
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
  // If queue is empty, return -1
  if (elementCount == 0) {
    return -1;
  }  
  // return the front element
  return elements[frontindex];
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
  return elementCount == 0;
}
