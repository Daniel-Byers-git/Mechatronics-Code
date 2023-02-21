#include "Rational.h"

int Rational::getNumer()
{
  return numer;
}

int Rational::getDenom()
{
  return denom;
}

void Rational:: reduce(Rational &r)
{  
    //Still not actually reducing
    //tried with "r.numer" "r.denom" and with "numer" and "denom"
    while ((r.numer % 2 == 0) && (r.denom % 2 == 0))
    {
        r.numer /= 2;
        r.denom /= 2;
    }
    for(int i = ((r.numer) * (r.denom)); i > 1; i--)
    {
        if((r.numer % i == 0) && (r.denom % i == 0))
        {
            r.numer /= i;
            r.denom /= i;
        }
    }
}

Rational Rational::operator+(Rational r)
{
    Rational tempRat;
    tempRat.numer = (numer * r.denom) + (r.numer * denom);
    tempRat.denom = denom * r.denom;
    reduce(tempRat);
    return tempRat;
}
Rational Rational::operator-(Rational r)
{
    Rational tempRat;
    tempRat.numer = (numer * r.denom) - (r.numer * denom);
    tempRat.denom = denom * r.denom;
    reduce(tempRat);
    return tempRat;
}
Rational Rational::operator*(Rational r)
{
    Rational tempRat;
    tempRat.numer = numer * r.numer;
    tempRat.denom = denom * r.denom;
    reduce(tempRat);
    return tempRat; 
}
Rational Rational::operator/(Rational r)
{
    Rational tempRat;
    tempRat.numer = numer * r.denom;
    tempRat.denom = denom * r.numer;
    reduce(tempRat);
    return tempRat;
}
Rational Rational:: operator+(int x)
{
    Rational tempRat;
    tempRat.numer = numer + (x * denom);
    tempRat.denom = denom;
    reduce(tempRat);
    return tempRat; 
}
Rational Rational:: operator-(int x)
{
    Rational tempRat;
    tempRat.numer = numer - (x * denom);
    tempRat.denom = denom;
    reduce(tempRat);
    return tempRat; 
}
Rational Rational:: operator*(int x)
{
    Rational tempRat;
    tempRat.numer = numer * x;
    tempRat.denom = denom;
    reduce(tempRat);
    return tempRat; 
}
Rational Rational:: operator/(int x)
{
    Rational tempRat;
    tempRat.numer = numer;
    tempRat.denom = denom * x;
    reduce(tempRat);
    return tempRat; 
} 
