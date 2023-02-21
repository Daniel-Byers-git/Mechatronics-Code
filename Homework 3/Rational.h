#include <iostream>

class Rational{
        int numer, denom;
    public:
        Rational() : numer(0), denom(0){}
        Rational(int num, int den) : numer(num), denom(den){}
        Rational operator+(Rational r);
        Rational operator-(Rational r);
        Rational operator*(Rational r);
        Rational operator/(Rational r);
        Rational operator+(int x);
        Rational operator-(int x);
        Rational operator*(int x);
        Rational operator/(int x);
        int getNumer();
        int getDenom();
        void reduce(Rational &r);
};
