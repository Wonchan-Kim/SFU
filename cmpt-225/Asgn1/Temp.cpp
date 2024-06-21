/*
 
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 *                    Its concrete data structure (CDT) is not expandable.  
 *                    This signifies that when this data collection becomes full,
 *                    you do not have to resize its data structure (not in this Assignment 1).  
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *
 * Author: AL, Tulika Varma
 * Last modified on: 29th May 2024
 * Tulika Varma 
 * 301557309
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() 
{
   // cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   for(unsigned int i = 0; i < MAX_ALPHA; i++)  // Initialize pointers to nullptr
   {
      elements[i] = nullptr;
      elementCount[i] = 0;
   }
}  

// Copy constructor - Covered in Lab 3
// Perfrom Deep copy of elements in rhs to follow class invariant 
MyADT::MyADT(const MyADT& rhs) 
{
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   for (unsigned int i = 0; i < MAX_ALPHA; i++)  // Copy elements and element counts from rhs
   {
      if (rhs.elements[i]) // Check if rhs has elements stored
      {
         elements[i] = new Profile[MAX_ELEMENTS]; // Allocate memory for elements and copy values
         for (unsigned int j = 0; j < rhs.elementCount[i]; j++) 
         {
            elements[i][j] = rhs.elements[i][j];
         }
         elementCount[i] = rhs.elementCount[i]; // Update element count
      } 
      else 
      {
         elements[i] = nullptr; // Set to nullptr if rhs doesn't have elements
         elementCount[i] = 0; // Set element count to zero
      }
    }
} 

// Overloaded assignment operator - Covered in Lab 4
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) { }
	
// Destructor - Covered in Lab 3
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() 
{
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above cout to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   for (unsigned int i = 0; i < MAX_ALPHA; i++) // Deallocate memory for elements
   {
      delete[] elements[i];
   }
}  

// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const 
{
   unsigned int count = 0;
   //while index is less than max amount of arrays, add together the value held at each index 
   //in element count (since each index represents elements in a letter array)
   
   for (unsigned int i = 0; i < MAX_ALPHA; ++i) // Sum up the element counts for all letters
   {
      count += elementCount[i];
   }
   return count;
}


// Description: Inserts an element in the data collection MyADT.
//              Returns "true" when the insertion is successfull, otherwise "false".
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted, MyADT's class invariants are still true
//                and the appropriate elementCount has been incremented.
// Time Efficiency: 
bool MyADT::insert(const Profile& newElement) 
{
   int index = 0;
   char firstletter = newElement.getSearchKey(); //Get first letter of element
   if (firstletter >= 'A' && firstletter <= 'Z')
   {
      unsigned int i;
      for (i = 0; i < elementCount[index]; i++)
      {
         if(elements[index][i] == newElement)
         {
            return false; //element already in so insertion fails
         }else{
            if (newElement.getUserName() < elements[index][i].getUserName())
            {
               break;
            }
         }
      }
      for (unsigned int n = elementCount[index]; n>i; n--)
      {
         elements[index][n] = elements[index][n-1];
      }
      elements[index][i] = newElement;
      elementCount[index]++;
      return true;

   }
   return 0;
}


// Description: Removes an element from the data collection MyADT. 
//              Returns "true" when the removal is successfull, otherwise "false".    
// Precondition: The data collection MyADT is not empty.  
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency: 
bool MyADT::remove(const Profile& toBeRemoved) 
{
   char firstletter = toBeRemoved.getSearchKey();

   if (firstletter >= 'A' && firstletter <= 'Z') 
   {
      unsigned int index = firstletter - 'A'; //convert letters to indices

      //check if element is already in array (use index loops in appropriate array)
      for (unsigned int i = 0; i < elementCount[index]; i++) 
      {
         if (elements[index][i] == toBeRemoved) 
         {
            // Shift elements to the left to remove the desired element
            for (unsigned int j = i; j < elementCount[index] - 1; j++) 
            {
               elements[index][j] = elements[index][j + 1]; //shift
            }
            // Decrease the element count
            elementCount[index]--;
            return true; //true if worked
         }
      }
   }
   return false; //false if failed
}

// Description: Removes all elements from the data collection MyADT. 
// Precondition: The data collection MyADT is not empty. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
// Time Efficiency: 
void MyADT::removeAll() 
{
  // set each element to zero
   for (unsigned int i = 0; i < MAX_ALPHA; i++) 
   {
      elementCount[i] =0; //set the elemts to zero
   }
   return;
}

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency: 
Profile* MyADT::search(const Profile& target) 
{
   //loop through appropriate array
   //if the index lies om target, return the pointer to that element
   char firstletter = target.getSearchKey();
   if (firstletter >= 'A' && firstletter <= 'Z') 
   {
      unsigned int index = firstletter - 'A'; //convert letters to indices
      if(elementCount[index]==0) 
      {
         return nullptr; //check to see if profiles in entry
      } else{
         for (unsigned int i = 0; i < elementCount[index]; i++) 
         {
         //within appropriate array, loop for element
         if(elements[index][i] == target) 
         {
            return (&elements[index][i]); //return pointer
         } 
         }
      }   
   }
   return nullptr;
}

// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
// Time Efficiency: 
void MyADT::print() 
{
   for (char letter = 'A'; letter <= 'Z'; letter++) 
   {
      unsigned int index = letter - 'A'; // Convert letters to indices
      if (elementCount[index] > 0) 
      {   
         //get each elements and print using getters
         for (unsigned int i = 0; i < elementCount[index]; i++) 
         {
            cout << elements[index][i].getUserName() << ", "
                  << elements[index][i].getName() << ", "
                  << elements[index][i].getEmail() << ", "
                  << elements[index][i].getBirthday() << endl;
         }         
      }
   }
} 

//  End of implementation file
