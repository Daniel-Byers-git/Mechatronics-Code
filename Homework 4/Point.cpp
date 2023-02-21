#include "Point.h"

using namespace std;

Point::Point() 
{
    x = y = 0;
}

void Point::setValues(double xVal, double yVal) 
{
    x = xVal;
    y = yVal;
}

double Point::getXvalue()
{
    return x;
}

double Point::getYvalue() 
{
    return y;
}

void Point::display() 
{
    cout << "(" << x << "," << y << ")" << endl;
}

double Point::dist(Point p) 
{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)); //Just pythgorean
}

double Point::dot(Point B)
{
    return (x * B.x) + (y * B.y); //Dot product of two "sides" (they're stored as points)
}

double Point::mag()
{
    return sqrt(pow(x,2) + pow(y,2));
}

double Point::slope()
{
    return y / x;
}