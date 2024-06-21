/*
* Circle.h
*
* Description: This class models a circle in two-dimensional
* Class Invariant: Radius is greater than 0
*
* Author: Wonchan Kim
* Creation date: May 10th, 2024
*/

class Circle {

    private:

        int x;
        int y;
        double radius;

    public:
        Circle() : x(0), y(0), radius(10) {}
        Circle(const int x, const int y, const double radius);
        int getX() const;
        int getY() const;
        double getRadius() const;

        void move(int horiz, int vert);
        void setRadius(double r);
        double computeArea() const;
        void displayCircle() const;
        bool intersect(Circle c) const;
};
