#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int art[7][33], col, row;   
    ifstream file;   
    file.open("Lab00data.txt");   
    for(row = 0; row < 7; row++)
    {
        for (col = 0; col < 33; col++) 
        {   
            file >> art[row][col]; 
        } 
    }

    file.close();

    for(row = 0; row < 7; row++)
    {
        for (col = 0; col < 33; col++) 
        {   
            cout << art[row][col] << " ";   
        }
        cout << endl << endl;   
    }

    

    for(row = 0; row < 7; row++)
    {
        for (col = 0; col < 33; col++)   
        { 
            cout << (char)art[row][col];  
        }
        cout << endl;   
    }

    

  return 0;
}