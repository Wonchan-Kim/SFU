//
//MyADTTestDriver.cpp - Assignment 1
//Author: Tulika Varma 
//Modified on: 30th May 2024
//


#include <iostream>
#include "Profile.h"
#include "MyADT.h"

using std::endl;
using std::cout;

int main() 
{
    MyADT test;

    // Create test profiles (double, so can check invalid scenario)
    Profile example1("tulika", "tulika varma", "tulika@gmail.com", "22/10/03");
    Profile example2("tulika", "tulika varma", "tulika@gmail.com", "22/10/03");
    Profile extra("kanika", "kanika varma", "kanika@gmail.com", "16/03/97");
    
    //TEST TO DEFAULT CONSTRUCTOR
    cout << "Test case 1: Default Constructor" << endl;
    cout << "Create class instance with default constructor" << endl;
    MyADT instance;
    unsigned int array = instance.getElementCount();
    cout << "Expected Result: Initialization was successfull" << endl;
    if(array == 0) //implies initialization worked and array is ready for values 
    { 
        cout << "Actual Result: Initialization was successfull" << endl;   
    } else {
        cout << "Actual Result: Initialization was not successfull" << endl;
    }
    cout << "************************************************************" << endl;

    //TEST FOR INSERT FUNCTION
    cout << "Test case 2: Insert Function" << endl;

    //VALID 
    cout << "Insert example user profile (testing insert)" << endl;
    cout << "Expected Result: insert is successfull" << endl;
    if(test.insert(example1)) {
        cout << "Actual Result: insert is successfull" << endl;
    } else {
        cout << "Actual Result: insert is unsuccessful" << endl;
    }

    //INVALID
    cout << "Insert a duplicate user profile (testing insert)" << endl;
    cout << "Expected Result: insert unsuccessfull" << endl;
    if(test.insert(example2)) {
        cout << "Actual Result: insert is successfull" << endl;
    } else {
        cout << "Actual Result: insert is unsuccessfull" << endl;
    }


    //TEST FOR SEACH FUNCTION

    cout << "************************************************************" << endl;
    //INVALID CASE
    cout << "Test case 3: Search Function" << endl;
    cout << "Test search function using profile that was not inserted" << endl;
    cout << "Expected Result: Profile was not found" << endl; //since profile is fake 

    if (test.search(extra) == nullptr) {
        cout << "Actual Result: Profile was not found" << endl;

    } else {
        cout << "Actual Result: Profile was found" << endl;
    }

    //VALID CASE
    cout << "Test search function using profile that was inserted" << endl;
    cout << "Expected Result: Profile was found" << endl; //since profile is fake 

    if (test.search(example2) == nullptr) {
        cout << "Actual Result: Profile was not found" << endl;

    } else {
        cout << "Actual Result: Profile was found" << endl;
    }

    //TEST REMOVE FUNCTION
    cout << "************************************************************" << endl;
    cout << "Test case 4: Remove Function" << endl;
    cout << "Test the remove function by removing inserted profile" << endl;
    cout << "Expected Result: Successfully removed" << endl;
    if (test.remove(example1)) {
        cout << "Actual Result: Successfully removed" << endl;
    } else {
        cout << "Actual Result: Could not be removed" << endl;
    }

    //TEST REMOVE ALL

    cout << "************************************************************" << endl;
    cout << "Test case 5: Remove all function" << endl;
    cout << "Test remove all by inserting, printing before and after removal" << endl;

    cout << "Before the removal..expected 2 profiles to print" << endl;
    test.insert(Profile(example1));
    test.insert(Profile(extra));
    test.print();

    //remove
    test.removeAll();

    cout << "After the removal, expected 0 profiles to print.." << endl;
    test.print();

    cout << "************************************************************" << endl;
    cout << "Test case 6: Print function" << endl;
    //PRINT TEST
    cout << "Test to see if profile prints out" << endl;
    test.insert(Profile(example1));
    test.print();

    //TEST THE GET ELEMENTCOUNT
    cout << "************************************************************" << endl;
    cout << "Test case 7: Get element count function" << endl;
    cout << "Test getelementcount, insert elements and request count" << endl;
    test.insert(Profile(example1));
    test.insert(Profile(extra));
    cout << "Expected Result: Count is 2" << endl;

    unsigned int countresult = 0;

    countresult = test.getElementCount();
    cout << "Actual Result: Count is " << countresult << endl;


    // //TEST COPY CONSTRUCTOR
    cout << "************************************************************" << endl;
    cout << "Test case 8: Copy Constructor" << endl;
    cout << "Test copy cosntructor by deep copy and returning element count" << endl;
    MyADT carray = (test);
    carray.print();
    carray.insert(example1);
    test.print();
    cout << "Expected result: there is 1 profile in this array" << endl;
cout << carray.getElementCount() << endl;
    if (carray.getElementCount()== 1) {
        cout << "Actual result: there is 1 profile in this array" << endl;
    } else {
        cout << "Actual result: Does not have same amount of elements" << endl;
    }

    //TEST DESTRUCTOR

    cout << "************************************************************" << endl;
    cout << "Test case 9: Destructor" << endl;
    cout << "Testing destructor: create array and delete" << endl;
    cout << "Expected Result: delete statements" << endl;
    cout << "Actual Result..." << endl;
    MyADT* newarray = new MyADT;
    newarray->insert(Profile(extra));


    delete newarray;
    
}