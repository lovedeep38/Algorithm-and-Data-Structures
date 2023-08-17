#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

//Default constructor
Circle::Circle() {
    x = 0;
    y = 0;
    radius = 10;
    totalCircles++;

    if(checkLeft()) {
        countForYAxis++;
    }
}

//Constructor with parameters
Circle::Circle(int x, int y, double radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    totalCircles++;

    if(checkLeft()) {
        countForYAxis++;
    }
}

//get the x coordinate of circle
int Circle::getX() const {
    return x;
}

//get the y coordinate of circle
int Circle::getY() const{
    return y;
}

//get the radius of circles
double Circle::getRadius() const{
    return radius;
}

//set the x and y coordinate of circle with given values
void Circle::translateXY(int X, int Y) {
    x += X;
    y += Y;
}

//set the radius of circle with given value
void Circle::setRadius(double r) {
    if(r <= 0) {
        throw invalid_argument("Radius must be positive");
    }else{
        radius = r;
    }
}

//compute the area of the circle
double Circle::computeArea() const{
    return 3.14*radius*radius;
}

//display the x and y coordinate and radius of circle
void Circle::displayCircle() const{
    cout << "[x = " << x << ", y = " << y << ", radius = " << radius << "]" << endl;
}

//return true two circles intersects each other
bool Circle::intersect(Circle c2) const{
    double distance = sqrt(pow(c2.getX() - x, 2) + pow(c2.getY() - y, 2));
    if(distance <= (radius + c2.getRadius())) {
        return true;
    }
    return false;
}

//get the total number of circle objects created
int Circle::getNumberOfCurrentCircles() {
    return totalCircles;
}

//count the number of circles created on the left side of y-axis
int Circle::getCirclesOnLeftOfYAxis() {
    return countForYAxis;
}

//check if the circle is on the left side of the y-axis
bool Circle::checkLeft() const{
    if(x < 0) {
        if(x + radius < 0) {
            return true;
        }
    }
    return false;
}

