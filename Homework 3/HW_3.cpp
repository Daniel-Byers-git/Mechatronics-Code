#include "Rational.h"
using namespace std;

ostream& operator<<(ostream& out, Rational r)
{
    out << r.getNumer() << "/" << r.getDenom();
    return out;
}

int main() 
{
    Rational a(1,2), b(5,2), c(1,4), d(5,3), e(3,2);

    cout << (a+1) + b*(c-2)*3 - d/e/2 << endl;

    return 0;
}   