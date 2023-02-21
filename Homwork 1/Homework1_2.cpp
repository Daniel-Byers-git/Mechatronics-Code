# include <iostream>
# include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream inData("HW01data.txt");
    float o1, o2;

    vector<float> O1;
    vector<float> O2;
    vector<float> radius;
    float R;
    int i = 0;

    while (!inData.eof()) {
        inData >> o1 >> o2;
        //cout << "omega1 = " << o1 << " rad/s, omega2 = "
        //                   << o2 << " rad/s" << endl;
        O1.push_back(o1);
        O2.push_back(o2);
        R = (28 / 2) * ( (O1.at(i) + O2.at(i)) / (O2.at(i) - O1.at(i)) ); // in cm
        radius.push_back(R);
        cout << "Turning radius: " << radius.at(i) << " cm" << endl;
        i++;
    }
    inData.close();
    return 0;
}