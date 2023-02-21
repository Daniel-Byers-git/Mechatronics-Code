 #include "Point.h"

class Polygon 
{
    protected:
        Point vertex[10];
        int numPoints;
        string shapeName;
        Point side[10]; //"sides" will be stored as a Point, but the x and y solely represent the change in x and y for that side.
                        // That is the only reason you can ge away with defining a side with the point class.
                        // There is no information on the location of the side.
    public:
        Polygon() : vertex({}),
                    numPoints(0),
                    shapeName(""), 
                    side({})   {}
        void setPoints(double x[], double y[], int numP); //defined below
        void setSides(); //sets sides of shape, defined below :: side[0] = ( difx(v0 & v1) , dify(v0 & v1)) and so on 
        void displayPoints(); // Writes shapeName and all vertices to the screen, defined below
        double getPerimeter(); //defined below
};

    //Definitions of Polygon functions
    void Polygon::setPoints(double x[], double y[], int numP)
    {
        for (int i = 0; i < numP; i++)
        {
            vertex[i].setValues(x[i], y[i]);
        }
    }
    void Polygon::displayPoints()
    {
        cout << "Points for " << shapeName << ": " << endl; 
        for (int i = 0; i < numPoints; i++)
        {
            vertex[i].display();    
        }
    
        //DELETE THIS AFTER DEBUG!!
        //  for (int i = 0; i < numPoints; i++)
        // {
        //     side[i].display();    
        //     cout << "    " << side[i].mag() << endl;
        // }
        
    }
    double Polygon::getPerimeter()
    {
        double perim = 0;
        for (int i = 0; i < numPoints - 1; i++)
        {
            perim += vertex[i].dist(vertex[i+1]);
        }
        perim += vertex[numPoints - 1].dist(vertex[0]);
        return perim;
    }
    void Polygon::setSides()
    {
        double SidexValue, SideyValue;
        for(int i = 0; i < numPoints; i++)
        {
            if(i < numPoints - 1)
            {
                SidexValue = (vertex[i+1].getXvalue() - vertex[i].getXvalue());
                SideyValue = (vertex[i+1].getYvalue() - vertex[i].getYvalue());
                side[i].setValues(SidexValue, SideyValue);
            }
            else
            {
                SidexValue = (vertex[0].getXvalue() - vertex[i].getXvalue());
                SideyValue = (vertex[0].getYvalue() - vertex[i].getYvalue());
                side[i].setValues(SidexValue, SideyValue);
            }
        }

    }

// Triangle: Subclass of Polygon
class Triangle : public Polygon 
{
    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
        double height, base;
        double getArea();
};
    //Triangle funtion defintions
    Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        shapeName = "Triangle";
        base = height = 1;
        numPoints = 3;
        double x[3] = {x1, x2, x3}, y[3] = {y1, y2, y3};
        setPoints(x, y, numPoints);
        setSides();
    }
    double Triangle::getArea()
    {
        return .5 * base * height;
    }

//Euilateral Triangle: Subclass of Triangle: Subclass of Polygon
class EquilateralTriangle : public Triangle 
{
    public:
        EquilateralTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
        double getHeight(Point A, Point B, Point C);
};
    //Definitions for Equalateral triangle functions
    EquilateralTriangle::EquilateralTriangle(double x1, double y1, double x2, double y2, double x3, double y3) :
    Triangle(x1, y1, x2, y2, x3, y3)
    {
        if (abs(side[0].mag() - side[1].mag()) > 1e-6 || abs(side[1].mag() - side[2].mag()) > 1e-6 || abs(side[2].mag() - side[0].mag()) > 1e-6)
        {
            cout << "Triangle is not Equilateral." << endl;
        } 
        shapeName = "Equilateral Triangle";
        base = side[0].mag();
        height = getHeight(vertex[0], vertex[1], vertex[2]);
    }
    double EquilateralTriangle::getHeight(Point A, Point B, Point C)
    {
        //Note: A , B = vertex[0] , vertex[1] respectively
        double height;
        Point Mid;
        double MidxValue = (A.getXvalue() + B.getXvalue()) / 2;
        double MidyValue = (A.getYvalue() + B.getYvalue()) / 2;
        Mid.setValues(MidxValue, MidyValue);
        height = Mid.dist(C);
        return height;    
    }


class RightTriangle : public Triangle 
{
    public:
        RightTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
};
    RightTriangle::RightTriangle(double x1, double y1, double x2, double y2, double x3, double y3) :
    Triangle(x1, y1, x2, y2, x3, y3)
    {
        if (abs(side[0].dot(side[1])) > 1e-6 && abs(side[1].dot(side[2])) > 1e-6 && abs(side[2].dot(side[0])) > 1e-6)
        {
            cout << "Triangle is not Right." << endl;
        }
        shapeName = "Right Triangle";
        height = 1; //necessary for "product / max" trick
        base = (side[0].mag()*side[1].mag()*side[2].mag()) / max( max(side[0].mag(),side[1].mag()) ,side[2].mag());
            //here instead of figuring out the two sides to multpily,
            //I just multiply all three together and divide by the largest.
            //This leaves me with b*h;
    }

class Parallelogram : public Polygon 
{
    public:
        Parallelogram(double x1, double y1, double x2, double y2, 
                      double x3, double y3, double x4, double y4);
        double base, height;
        bool right = false, parallel = true;
        double getArea();
};

    Parallelogram::Parallelogram(double x1, double y1, double x2, double y2, 
    double x3, double y3, double x4, double y4) 
    {   
        shapeName = "Parallelogram";
        base = height = 1;
        numPoints = 4;
        double x[4] = {x1, x2, x3, x4}, y[4] = {y1, y2, y3, y4};
        setPoints(x, y, numPoints); 
        setSides();
        if(abs(side[0].dot(side[1])) < 1e-6 && abs(side[1].dot(side[2])) < 1e-6 && abs(side[2].dot(side[3])) < 1e-6 && abs(side[3].dot(side[0])) < 1e-6)
        {
            right = true;
        }
        if(!right)
        {
            if(side[0].slope() != side[2].slope() || side[1].slope() != side[3].slope())
            {
                cout << "Opposite sides are not parallel." << endl;
                parallel = false;
            }
        }
    }
    double Parallelogram::getArea()
    {
        return abs(((vertex[1].getXvalue() - vertex[0].getXvalue()) * (vertex[2].getYvalue() - vertex[0].getYvalue()))
                    - ((vertex[1].getYvalue() - vertex[0].getYvalue()) * (vertex[2].getXvalue() - vertex[0].getXvalue())));
    }


class Rectangle : public Parallelogram 
{
    public:
        Rectangle(double x1, double y1, double x2, double y2, 
                  double x3, double y3, double x4, double y4);
};

Rectangle:: Rectangle(double x1, double y1, double x2, double y2, 
                  double x3, double y3, double x4, double y4) :
    Parallelogram(x1, y1, x2, y2, x3, y3, x4, y4)
    {
        shapeName = "Rectangle";
        if (!right && parallel)
        {
            cout << "Angles not right." << endl;
        }

    }