#include <iostream>
#include <fstream>
#include "complex.h"

using namespace std;



int main()
{
    /*
    const int n = 5;
    double yMin = -2, yMax = 18, y[n];
    for(int x = 0; x < n; x++)
    {
        y[x] = 5*x - 2;
    }
    */

    Complex z1(1.4, 2.1);
    Complex z2(-3.2, 4.6);

    cout << (z1*z2) + (z1 / (z2 - z1)) << endl;

    // Variables for storing Complec #s
    Complex plot1[20];
    Complex plot2[24][20];
    double mags1[20];
    double mags2[24][20];
    int x = 0;

    for (double i = -1.5; i <= .5; i += .1)
    {
      plot1[x].setVals(i, -1.2);
      plot1[x] = plot1[x] * plot1[x] + plot1[x];
      mags1[x] = plot1[x].getMag();
      //cout << x << " " << i << " " << mags1[x] << endl; //test print line for 1D
      x++;
    }

    ofstream compMag1;
    compMag1.open ("ComplexMagnitudes1D.txt");
    for (int i = 0; i < 20; i++)
    {
      compMag1 << mags1[i] << " ";
    }
    compMag1 << endl;
    compMag1.close();


    //2D version//
    double r = -1.5, i = -1.2;
    int testrow = 0;
    int testcol = 0;

    for(int row = 0; row < 24; row++)
    {
          // testrow++;
          // cout << testrow << " : ";
      for(int col = 0; col < 20; col++)
      {
          // testcol++;
          // cout << testcol << " ";
        plot2[row][col].setVals(r, i);
        plot2[row][col] = plot2[row][col] * plot2[row][col] + plot2[row][col];
        mags2[row][col] = plot2[row][col].getMag();
        r += .1;
        //cout << mags2[row][col] << " "; // test line for 2D
      }
          //cout << endl;
          // testcol = 0;
      r = -1.5;
      i += .1;
    }
    i = 0;
    
    ofstream compMag2;
    compMag2.open ("ComplexMagnitudes2D.txt");
    for (int row = 0; row < 24; row++)
    {
      for(int column = 0; column < 20; column++)
      {
        compMag2 << mags2[row][column] << " ";
      }
      compMag2 << endl;
    }
    compMag2.close();

    return 0;
}
