#include "Box.h"

string Box::getPin(){
    return to_string(pin);
}

//Operator overloading of + passing in right hand side(RHS)
Box Box::operator+(Box &RHS){
    Box Return_Box;
    int common_den = b * RHS.b;
    int num = (a*RHS.b) + (b*RHS.a);    
    Return_Box.a = num;
    Return_Box.b = common_den;
    return Return_Box;
}

Box operator+(double passed_in_double, Box &RHS){
    Box Return_Box;
    Return_Box.a = passed_in_double + RHS.a;
    Return_Box.b = passed_in_double + RHS.b;
    return Return_Box;
}

ostream &operator<<(ostream &out, Box &RHS){
    out << "Box Value A: " << RHS.a << " Box Value B: " << RHS.b;
    return out;
}

ostream &operator<<(ostream &out, char *RHS){
    out << "The Pin: " << RHS;
    return out;
}


//opeartor overloading passing in number passed into []
//Void since there is no return
void Box::operator[](int index){
    cout << "We do not allow iteration" << endl;
}
