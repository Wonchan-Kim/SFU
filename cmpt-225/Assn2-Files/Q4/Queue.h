/* 
 * Queue.h - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jaclyn Sunardi and Wonchan Kim
 * Date: June 04 2024
 */
 
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue {

/* You cannot remove/modify the data members below, 
   except for the "int elements[INITIAL_CAPACITY];". 
   However, you can add more data members.           */
	
  private:
    constexpr static unsigned int INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
    int* elements;                     // To do: replace this array with a pointer to an array - see Question 4

    unsigned int elementCount = 0;             // Number of elements in the Queue - if you need it!
    unsigned int capacity = INITIAL_CAPACITY;  // Initial capacity of the data structure (number of cells in the array)
    unsigned int frontindex = 0;               // Index of front element (next dequeued/peeked element)
    unsigned int backindex = 0;                // Index of where the next element will be enqueued                     

/* You can add private methods. */
void resize(unsigned int newCapacity);


  public:
 
/* You cannot remove/modify the public methods below.  
   This also applies to their documentation. 
   However, you can add public methods if you need them 
   like "printQueue()", etc.      

   However, you will need to add a destructor, a copy constructor 
   as well as an overloaded assignment = operator - see Question 4
*/

    // Description: Constructor
    Queue();

    // Description: Copy constructor
    Queue(const Queue& toBeCopied);

    // Description: Destructor
    ~Queue();

    // Description: Overload Assignment = operator
    Queue& operator=(const Queue& other);

    // Description: Inserts newElement at the back of Queue
    // Time Efficiency: O(1)
    void enqueue(int newElement);

    // Description: Removes the frontmost element
    // Precondition: Queue not empty
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns a copy of the frontmost element
    // Precondition: Queue not empty
    // Time Efficiency: O(1)
    int peek() const;

    // Description: Returns true if and only if Queue empty
    // Time Efficiency: O(1)
    bool isEmpty() const;
        
};
#endif