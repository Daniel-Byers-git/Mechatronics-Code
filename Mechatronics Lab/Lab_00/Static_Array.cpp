#include <iostream>
using namespace std;

int main ()
{
    int value[5] = {5,4,3,2,1};
    cout << value[3] << endl;
    value[3] = value[0] + value[4];
    cout << value[3] << endl;
    return 0;
}