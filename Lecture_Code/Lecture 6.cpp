#include <iostream>
#include <vector>
// #include ""
// Preprocessor directive = #
#define PI 3.14
//examples of preprocess directives
// #ifdef
// #ifndef
// #else
// #elif
// #pragma
// #
// argc = argument counter
// argv = argument values
using namespace std;
// :: = scope resolutions

//struct definition example
struct person{
    string name;
    int age;
    string location;
    int zip;
};

//Class Information Found In Header Files (class.h)
class person_class{
    public:
        string name;
        //default constructor
        person_class();
        //destructor
        ~person_class();
        person_class(string passed_name) : name(passed_name){};
        person_class(string, string, int, int);
        void set_location();
    private:
        string location;
        int zip;
    protected:
        int age;
};

//normally found in separate file e.g. person_class.cpp
person_class::person_class(){
    cout << "Default Constructor" << endl;
    name = "Default";
    location = "Marietta";
    zip = 30090;
    age = 20;
}

// one way to define overloaded constructor. Assing inside {}
// person_class::person_class(string passed_name, string passed_location, int passed_zip, int passed_age){
//     cout << "Overload Constructor" << endl;
//     name = passed_name;
//     location = passed_location;
//     zip = passed_zip;
//     age = passed_age;
// }

//prefered way of defining constructor using : notation
//:: = the overloaded constructor person_class belongs to person_class.
//: assignment of passed in values before {}
person_class::person_class(string passed_name, 
                           string passed_location, 
                           int passed_zip, 
                           int passed_age) : name(passed_name), 
                                             location(passed_location), 
                                             zip(passed_zip), 
                                             age(passed_age){
    cout << "Overload Constructor" << endl;
}

person_class::~person_class(){
    cout << "Destructor Called" << endl;
    //Free up memory in this location
}

// person_class::person_class(string passed_name){
//     cout << "Overload Constructor" << endl;
//     name = passed_name;
//     location = "Marietta";
//     zip = 30090;
//     age = 20;
// }

void person_class::set_location(){

}


int main(int argcount, char *argvalues[]){
    // person person_a;
    // person_a.name = "Sample Name";
    // person_a.age = 20;
    // person_a.zip = 30046;
    // person_a.location = "Marietta";
    person_class person_obj;
    person_class person_obj_2("Sample Name", "Atlanta", 30033, 21);
}

