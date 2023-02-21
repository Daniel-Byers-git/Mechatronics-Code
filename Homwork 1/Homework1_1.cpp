#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> fibonnaci = {0, 1};
    
    int f = 0;
    int l = 0, h = 1;

    while (f <= 1000)
    {
        f = fibonnaci.at(l) + fibonnaci.at(h);
        fibonnaci.push_back(f);
        l++;
        h++;
    }

    int r = 0;
    while (r < int(fibonnaci.size()) - 1)
    {
        cout << fibonnaci.at(r) << endl;
        r++;
    }
}