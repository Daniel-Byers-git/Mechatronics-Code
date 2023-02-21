#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
        double  real, imag;
    public:
        Complex() : real(1), imag(1){}
        Complex(double  r, double i) : real(r), imag(i){}
        void    setVals  (double  r, double i);
        double  getReal(); // Return real part
        double  getImag(); // Return imaginary part
        double  getMag(); // Return magnitude
        Complex operator+(Complex c); // Add two complex numbers
        Complex operator-(Complex c); // Subtract two complex numbers
        Complex operator*(Complex c); // Multiply two complex numbers
        Complex operator/(Complex c); // Divide two complex numbers
};

double Complex::getReal(){
    return real;
}

double Complex::getImag(){
    return imag;
}

double Complex::getMag(){
    double magnitude;
    magnitude = sqrt( pow(real, 2) + pow(imag, 2) ) ;
    return magnitude;
}

void Complex::setVals(double r, double i){
    real = r;
    imag = i;
}

Complex Complex::operator+(Complex c){
    Complex tmpComp;
    tmpComp.real = real + c.real;
    tmpComp.imag = imag + c.imag;
    return tmpComp;
}

Complex Complex::operator-(Complex c){
    Complex tmpComp;
    tmpComp.real = real - c.real;
    tmpComp.imag = imag - c.imag;
    return tmpComp;
}

Complex Complex::operator*(Complex c){
    Complex tmpComp;
    tmpComp.real = (real * c.real) - (imag * c.imag);
    tmpComp.imag = (real * c.imag) + (imag * c.real);
    return tmpComp;
}

Complex Complex::operator/(Complex c){
    Complex tmpComp;
    double denom = pow(c.real, 2) + pow(c.imag, 2);
    tmpComp.real = (real * (c.real / denom)) + (imag * (c.imag / denom));
    tmpComp.imag = (imag * (c.real / denom)) - (real * (c.imag / denom));
    return tmpComp;
}

ostream& operator<<(ostream& out, Complex z) // Write z to the output stream out
{
    out << z.getReal() << " + (" << z.getImag() << ")i";
    return out;
}

Complex operator/(double x, Complex z); // Return reciprocal of z multiplied by scalar x
