#include "Circle.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
int main() {
    Circle** circleArray = nullptr;
    unsigned int size;
    
    cin >> size;
    cout << "size is " << size << endl;
    if (size < 0) {
        cout << "Size of array should be bigger than 0" << endl;
        return -1;
    }
    circleArray = new Circle* [size];
    
    for(int i = 0; i < size; i++){
        int x, y;
        double radius;

        cin >> x >> y >> radius;
        circleArray[i] = new Circle(x,y,radius);
    }

    for(int i = 0; i < size; i++){
        cout << "Index : " << i << " ";
        circleArray[i] -> displayCircle();
        cout << "Area : " << setprecision(6) << circleArray[i] -> computeArea();
        cout << endl;
    }
    
    for(int i = 0; i < size; i++){
        delete circleArray[i];
    }

    delete[] circleArray;
}