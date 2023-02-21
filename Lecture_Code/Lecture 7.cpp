#include <iostream>
#include <vector>

using namespace std;

//Class Definition
class Box{
    public:
        //Public Class Variable a,b
        int a;
        int b;
        //Default Constructor
        Box():a(0),b(0){}
        //Overloaded Constructor using : for initialization
        Box(int passed_in_a, int passed_in_b):a(passed_in_a),b(passed_in_b){}
        //Operator overloading of + sign
        Box operator+(Box &);
        //Operator overloading of []
        void operator[](int);
    private:

};

//Operator overloading of + passing in right hand side(RHS)
Box Box::operator+(Box &RHS){
    Box Return_Box;
    Return_Box.a = a + RHS.a;
    Return_Box.b = b + RHS.b;
    return Return_Box;
}

//opeartor overloading passing in number passed into []
//Void since there is no return
void Box::operator[](int index){
    cout << "We do not allow iteration" << endl;
}

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
    std::cout << "Box A: " << box_sum.a << endl << "Box B: " << box_sum.b << endl;
    //Showing the overload for []
    box_sum[2];
}

