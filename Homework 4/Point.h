#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Point {
        double x, y;    
    public:
        Point();
        void setValues(double xVal, double yVal);
        double getXvalue();
        double getYvalue();
        void display();
        double dist(Point p);
        double dot(Point B);
        double mag();
        double slope();
};

#endif