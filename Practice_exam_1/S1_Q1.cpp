#include <iostream>
#include <vector>

using namespace std;

typedef vector <double> even_spaced;

void assignVal (even_spaced & A, int i, int count, double inc)
{
    double tmpVal = 1; 
    A.push_back(tmpVal);
    for (int k = 0; k < count; k+=i)
    {
        tmpVal += inc;
        A.push_back(tmpVal);
    }
}

int main ()
{
    double number;
    cout << "Enter number of points: ";
    cin >> number;
    int count = number;

    double increment = 100 / number; 
    // cout << increment;

    even_spaced every, thirds;

    assignVal(every, 1, count, increment);
    for (int j = 0; j < 5; j++)
    {
        cout << every[j] << " ";
    }
}