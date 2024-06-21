#include <iostream>
#include "Circle.h"
#include <iomanip>

using std::cout;
using std::endl;

Circle::Circle(const int initialX, const int initialY, const double initialRadius) : x(initialX), y(initialY) {
    if(initialRadius < 0)
        radius = 10.0;
    else
        radius = initialRadius;
}

int Circle::getX() const {
    return x;
}

int Circle::getY() const {
    return y;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::move(int horiz, int vert) {
    x = horiz;
    y = vert;
}

void Circle::setRadius(double r) {
    if(r <= 0)
        radius = 10.0;
    else
        radius = r;
}

double Circle::computeArea() const {
        return 3.1415926548 * radius * radius;
}

void Circle::displayCircle() const {
    cout << "x = " << x <<", y = " << y << ", radius = " << radius << endl;

}

bool Circle::intersect(Circle c) const {
    double dx = static_cast<double>(x - c.getX());
    double dy = static_cast<double>(y - c.getY());
    double distanceSquared = dx * dx + dy * dy;

    double radiusofC = c.getRadius();

    return (radiusofC - radius) * (radiusofC - radius) <= distanceSquared && distanceSquared <= (radiusofC + radius) * (radiusofC + radius);
}
