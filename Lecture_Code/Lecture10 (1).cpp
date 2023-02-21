#include <iostream>

using namespace std;

class Polygon{ //Base Class
    public:
        Polygon() : length(0), 
                    width(0), 
                    number_of_sides(0), 
                    exempt_from_defered(5) {}
                    
        void Print();
        double length;
        double width;

    private:
        double exempt_from_defered;

    protected:
        double number_of_sides;
};

void Polygon::Print()
{
  cout << "Length is:" << length << 
          " Width is: " << width << 
          " number of sides are " << 
          number_of_sides << 
          endl;
}

class Rectangle : public Polygon { //Derived
    public:
        void CalculateArea();
        void setNumberOfSides(double);
};

void Rectangle::setNumberOfSides(double sides){
    number_of_sides = sides;
}
   
void Rectangle::CalculateArea(){
    std::cout << "Area Of A Rectangle is: " << 
                 length * width << 
                 std::endl;
}

class Triangle : public Polygon {
    public:
        void CalculateArea();
        void setNumberOfSides(double);
        void setExempt(double);
};

void Triangle::setExempt(double value){
    return;
    // exempt_from_defered = value;
}

void Triangle::setNumberOfSides(double sides){
    number_of_sides = sides;
}

void Triangle::CalculateArea(){
    std::cout << "Area Of A Triangle is: " << 
                 ((length * width) / 2) << 
                 std::endl;
}


int main()
{ 
    Rectangle r; 
    Triangle t; 
    Polygon p;

    r.length = 3;
    r.width = 4;
    r.CalculateArea();

    t.length = 2;
    t.width = 4; // Assuming Width is the height of a triangle
    t.CalculateArea();

    // Can protected values be set?
    // r.number_of_sides = 5;
    // r.setNumberOfSides(4);
    // t.setNumberOfSides(3);

    // Will this work?
    // std::cout << "Number of Recangle sides: " << r.number_of_sides << std::endl;
    // std::cout << "Number of Triangle sides: " << t.number_of_sides << std::endl;
  
    //Can I do this?
    t.setExempt(3);

    r.Print();
    t.Print();

    // What about this. Can I do this?
    // Polygon p;
    // p.Print();
}

