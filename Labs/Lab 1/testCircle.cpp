#include <iostream>
#include "Circle.h"

using namespace std;
int Circle::totalCircles = 0;   //defining static member variable

int Circle::countForYAxis = 0;

int main() {
    cout << "Test case 1 : Creating circle with default constructor" << endl;
    Circle c1;
    c1.displayCircle();
    cout << c1.computeArea() << endl;


    cout << "\nTest Case 2: changing values of x, y and radius" << endl;
    c1.translateXY(-10, 10);
    c1.setRadius(3);
    c1.displayCircle();
    cout << c1.computeArea() << endl;

    cout << "\nTest Case 3: check if two circles intersecting" << endl;
    Circle c2(3,2,9);
    Circle c3(-4,-2,9);
    cout << "\nCase1: intersecting" << endl;
    if(c2.intersect(c3)) {          
        cout << "Two circles intersecting" << endl;
    }else{
        cout << "Two circles do not intersect" << endl;
    }

    Circle c4(0, 0, 2);
    cout << "\nCase2: one circle is the inside second circle , intersecting" << endl;
    if(c3.intersect(c4)) {          
        cout << "Two circles intersecting" << endl;
    }else{
        cout << "Two circles do not intersect" << endl;
    } 

    Circle c5(5, 6, 3);
    cout << "\nCase3: not intersecting" << endl;
    if(c4.intersect(c5)) {
        cout << "Two circles intersect" << endl;
    }else{
        cout << "Two circles do not intersect" << endl;
    }

    cout << "\nTest Case 4: getting total number of circles created and circles created on left side of y-axis" << endl;
    
    Circle c6(-7, 8, 7); //circle touching y-axis(does not count for left of y-axis)
    Circle c7(-4, 3, 2); //circle created on left side of y-axis
    Circle c8(-6, 5, 5); //circle created on left side of y-axis

    cout << "\nTotal number of circles created: " << Circle::getNumberOfCurrentCircles() << endl;
    cout << "\nTotal number of circles created on left side of y-axis: " << Circle::getCirclesOnLeftOfYAxis() << endl;
}