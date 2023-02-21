
#include <iostream>
#include "Box.h"

// g++ -o my_launcher.exe .mainprog.cpp .\Complex.cpp
//Main function
int main(int argcount, char *argvalues[]){
    //Defining box_1 object and assinging it 2,3
    Box box_1(2,3);
    //Defining box_2 object and assinging it 3,4
    Box box_2(3,4);
    //Defining empty box object. Default constructor assinged to 0,0
    Box box_sum;
    //Operator overload example adding box_1 and box_2. RHS (box_2) is passed in
    box_sum = box_1 + box_2;
    //Printing the information inside box_sum
    std::cout << "Box A: " << box_sum.a << endl << " Box B: " << box_sum.b << endl;
    //Showing the overload for []
    box_sum[2];
    //checking the left hand side

    box_sum = 10 + box_1;
    cout << box_sum << endl;
    cout << box_sum.getPin() << endl;
}

