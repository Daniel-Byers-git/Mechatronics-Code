#include <iostream>
using namespace std;

int main()
{
    int val[4];

    cout << "Enter number 1: ";
    cin >> val[1];

    cout << "Enter number 2: ";
    cin >> val[2];

    cout << "Enter number 3: ";
    cin >> val[3];

    cout << "Enter number 4: ";
    cin >> val[4];

    /*
    if(val > 100)
    {
        cout << "Large number" << endl;
    }
    else
    {
        cout << "Small number" << endl;
    }
    */

    int temp;
    if(val[1] > val[2])
    {
        temp = val[2];
        val[2] = val[1];
        val[1] = temp;
    }
    
    if(val[2] > val[3])
    {
        temp = val[3];
        val[3] = val[2];
        val[2] = temp;
    }

    if(val[3] > val[4])
    {
        temp = val[4];
        val[4] = val[3];
        val[3] = temp;
    }

      if(val[1] > val[2])
    {
        temp = val[2];
        val[2] = val[1];
        val[1] = temp;
    }
    
    if(val[2] > val[3])
    {
        temp = val[3];
        val[3] = val[2];
        val[2] = temp;
    }

    if(val[3] > val[4])
    {
        temp = val[4];
        val[4] = val[3];
        val[3] = temp;
    }
      if(val[1] > val[2])
    {
        temp = val[2];
        val[2] = val[1];
        val[1] = temp;
    }
    
    if(val[2] > val[3])
    {
        temp = val[3];
        val[3] = val[2];
        val[2] = temp;
    }

    if(val[3] > val[4])
    {
        temp = val[4];
        val[4] = val[3];
        val[3] = temp;
    }

    cout << val[1] << " " << val[2] << " " 
         << val[3] << " " << val[4] << endl;
    
    return 0;
}
