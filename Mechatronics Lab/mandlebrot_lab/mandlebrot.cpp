#include <iostream>
#include <fstream>
#include "complex.h"

using namespace std;

int main()
{
    ifstream domain("domain.txt");
    ofstream nFile("nFile.txt");
    Complex z0, zn;
    int numR = 500, numC = 500;
    double rMax, rMin, iMax, iMin, n = 0;
    domain >> rMin; domain >> rMax; domain >> iMin; domain >> iMax;
    for(double r = 0; r < numR; r++)
    {
        for(double c = 0; c < numC; c++)
        {
            z0.setVals( (rMax - rMin) * c / (numC - 1) + rMin, (iMax - iMin) * r / (numR - 1) + iMin);
            n = 0; zn = z0;
            while (n < 5000 && zn.getMag() < 2)
            {
                zn = zn * zn + z0;
                n++;
            }
            nFile << n << " ";
        }
        nFile << endl;
    }
    domain.close(); nFile.close();
    return 0;
}