#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

int main ()
{
    int random[10];
    for (int i = 0; i < 10; i++)
    {
        random[i] = rand() % 26 + 25;
    }

    for (int l = 0; l < 10; l++)
    {
        cout << random[l] << " ";
    }
    cout << endl;

    int temp;
    for (int c = 0; c < 9; c++)
    {
        if(random[c] > random[c+1])
        {
            temp = random[c];
            random[c] = random[c+1];
            random[c+1] = temp;
        }
         for (int l = 0; l < 10; l++)
        {
            cout << random[l] << " ";
        }
    cout << endl;
    }

    return 0;
}