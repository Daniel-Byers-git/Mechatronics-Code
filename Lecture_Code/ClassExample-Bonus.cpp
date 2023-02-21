#include <iostream>
#include <vector>
#include <ostream>

class ClassA {
    public:
        //Constructors
        ClassA();
        ClassA(int, int);

        int calcArea();
        int calcArea(int, int);

        ClassA operator+(ClassA &); // Add 
	    ClassA operator-(ClassA &); // Subtract
	    ClassA operator*(ClassA &); // Multiply
	    ClassA operator/(ClassA &); // Divide
        void operator==(ClassA &);
        void operator[](int);

        //Destructor
        ~ClassA();

        //Copy Constructor
        ClassA(const ClassA &);

        //Public Class Values
        int l;
        int w;

        //TODO: Extra Credit 1 Point Overall Grade. Complete The Following Code.
        //TODO: Add a Security Question The First Time A User Inputs The Pin Correctly.
        //TODO: Hint use cin. 
        //TODO: If The number of tries exceed the first time (Before Security Question) allow selection of a new pin
        //TODO: Limit the number of tries for the pin after security question selection
        //TODO: Lock The Account After N Number of Tries
        //TODO: Cannot update pin using update_pin once security question is updated
        //TODO: Must use reset_pin_with_security_question to change pin. 
        void try_pin(int);
        void update_pin(int);
        // int number_of_tries;
        // void limit_the_number_tries(int);
        // std::string security_question;
        // std::string security_answer;
        // void reset_pin_with_security_question(int);
    private:
        int passcode_pin = 1234;
};

std::ostream& operator<<(std::ostream& out, ClassA &a){
    out << a.l << "/" << a.w;
    return out;
}

ClassA ClassA::operator+(ClassA &passed_in){
    ClassA tmpHolding;
    tmpHolding.l = l + passed_in.l;
    tmpHolding.w = w + passed_in.w;
    return tmpHolding;
}


void ClassA::operator==(ClassA &pass_in_obj){
    if (l == pass_in_obj.l){
        std::cout << "They Are equal" << std::endl;
    } else {
        std::cout << "Not equal in length" << std::endl;
    }
}

ClassA ClassA::operator-(ClassA &a){
    ClassA tmpHolding;
    tmpHolding.l = l - a.l;
    tmpHolding.w = w - a.w;
    return tmpHolding;
}

ClassA ClassA::operator*(ClassA &a){
    ClassA tmpHolding;
    tmpHolding.l = l * a.l;
    tmpHolding.w = w * a.w;
    return tmpHolding;
}

ClassA ClassA::operator/(ClassA &a){
    ClassA tmpHolding;
    tmpHolding.l = l / a.l;
    tmpHolding.w = w / a.w;
    return tmpHolding;
}

void ClassA::operator[](int index){
    std::cout << "You are not allowed to access using []" << std::endl;
}

ClassA::ClassA(){
    std::cout << "Default Constructor Called" << std::endl;
}


ClassA::ClassA(int length, int width) : l(length), 
                                        w(width){
    std::cout << "Assignment (Overloaded) Constructor Called " << std::endl;
}

ClassA::~ClassA(){
    std::cout << "Destructor Called " << std::endl;
    std::cout << "***Cleaning Memory " << std::endl;
    std::cout << "***If your class does not have a destructor, \n"
                 "***C++ compiler will do a decent job at performing cleanup. \n"
                 "***However it is recommended to always have a destructor" << std::endl;
}

ClassA::ClassA(const ClassA &variableIAmCopyingFrom) : l(variableIAmCopyingFrom.l), w(variableIAmCopyingFrom.w){
    std::cout << "Copy Constructor Called" << std::endl;
}

void ClassA::try_pin(int pin){
    if (pin == passcode_pin){
        std::cout << "You Entered The Right Password" << std::endl;
    }
}

int ClassA::calcArea(){
    return l*w;
}

int ClassA::calcArea(int length, int width){
    return length*width;
}

void ClassA::update_pin(int pin){
    passcode_pin = pin;
}

int main(int argc, char* argv[]){
    std::cout << "Hello From Main" << std::endl;
    // std::cout << "empty SQ declared" << std::endl;
    // ClassA sq;

    // std::cout << std::endl;
    // std::cout << "SQ() declared" << std::endl;
    // ClassA sq2(1,3);

    // std::cout << std::endl;
    // std::cout << "SQ = {} declared" << std::endl;
    //It is better to use curly brackets with later versions of C++ for assignment
    // ClassA sq3 = {1,3};
    // std::cout << sq3.l << std::endl;

    // std::cout << sq3.calcArea() << std::endl;
    // std::cout << sq3.calcArea(4,5) << std::endl;

    // std::cout << std::endl;
    // //Copy Constructor
    // ClassA copy_variable = sq3;
    // std::cout << "l in copy_variable is: " << copy_variable.l << std::endl
    //           << "w in copy_variable is: " << copy_variable.w << std::endl;

    // std::cout << std::endl;
    // ClassA *sample = new ClassA(1,2); //malloc
    // delete sample;
    // std::cout << "Descructor Before Exit" << std::endl;
    
    // std::cout << std::endl;
    // std::vector<ClassA>  vector_of_class_items(0); 
    // std::cout << "Push Back ClassA Object To Vector" << std::endl;
    // vector_of_class_items.push_back (ClassA(1,2));
    // std::cout << "Accessing ClassA Vector At Index 0" << vector_of_class_items.at(0).w << std::endl;

    // std::cout << "Push Back ClassA Object To Vector" << std::endl;
    // vector_of_class_items.push_back (ClassA(3,4));

    // std::cout << "Push Back ClassA Object To Vector" << std::endl;
    // vector_of_class_items.push_back (ClassA(5,6));

    //Erase Takes in an Iterator type not an index. 
    // vector_of_class_items.erase(vector_of_class_items.begin());

    std::cout << std::endl;
    ClassA sq4 = {10,11};
    std::cout << sq4 << std::endl;
    // double area = sq4.calcArea();
    // double area = sq4.calcArea(x,y);

    std::cout << std::endl;
    ClassA sq5 = {20,20};
    ClassA sq6 = {20,20};
    sq5 = sq6;
    ClassA sq7;

    sq7 = sq6 + sq5;
    std::cout << sq6.l << " " << sq6.w << std::endl; 
    
    sq6[1];

    std::cout << std::endl;
    std::cout << "Program Finished" << std::endl;
    std::cout << std::endl;
}


//What can be overloaded
// +    -    *    /      %        ^
// &    |    ~    !,        =
//     =      ++        --
//     ==    !=      &&        ||
// +=    -=    /=    %=      ^=        &=
// |=    *=    =      []        ()
// ->    ->*    new    new []      delete    delete []

//Cannot be overloaded . 
//Scope Resolution Operator ::    
//Pointer-to-member Operator .*    
//Member Access or Dot operator .    
//Ternary or Conditional Operator ?:
//Object size Operator sizeof 
//Object type Operator typeid 