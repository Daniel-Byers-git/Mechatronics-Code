#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <vector>

using namespace std;

//Class Definition
class Box{
    public:
        //Public Class Variable a,b
        int a;
        int b;
        //Default Constructor
        Box():a(0),b(0){}
        //Overloaded Constructor using : for initialization
        Box(int passed_in_a, int passed_in_b):a(passed_in_a),b(passed_in_b){}
        //Operator overloading of + sign
        Box operator+(Box &);
        // Non-Member Function Access Using Friend Keyword
        friend Box operator+(double, Box &);
        // << output stream overload
        friend ostream &operator<<(ostream &, Box &);
        friend ostream &operator<<(ostream &, char *);
        void operator[](int);

        string getPin();

    private:
        int pin = 1234;
};

#endif
