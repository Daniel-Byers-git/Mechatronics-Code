#include <iostream>
#include <vector>
// #include ""
// Preprocessor directive = #
#define PI 3.14
// argc = argument counter
// argv = argument values
using namespace std;
// :: = scope 

void add_num(int *);
void add_num(int);
// void add_num();

struct person{
    string name;
    int age;
    string location;
    int zip;
};

void passing_person(person &);
void print_person(person &);

class person_class{
    public:
        person_class();
        person_class(string name, int age, string location, int zip);
        person_class(string name);
        string name;
        void set_age(int age);
        void set_location(string location, int zip);
    private:
        int age;
    protected:
        string location;
        int zip;
};

person_class::person_class(){
    cout <<" Default constructor " << endl;
}

person_class::person_class(string passed_name, int passed_age, string passed_loc, int passed_zip){
    cout <<" Overloaded Constructor " << endl;
    name = passed_name;
    age = passed_age;
    location = passed_loc;
    zip = passed_zip;
}

person_class::person_class(string passed_name): name(passed_name) {
    cout <<" Overloaded Constructor Number Two " << endl;

}

void person_class::set_age(int passed_age){
    age = passed_age;
}

void person_class::set_location(string passed_loc, int passed_zip){
    location = passed_loc;
    zip = passed_zip;
}

int main(int argcount, char *argvalues[]){
    int tmp = 1;
    add_num(tmp);
    cout << "TMP Value After Fist Call: " << tmp << endl;
    add_num(&tmp);
    cout << "TMP Value After Sec Call: " << tmp << endl;
    person person_a;
    person_a.name = "Sample Name";
    person_a.age = 20;
    person_a.zip = 30046;
    person_a.location = "Marietta";
    passing_person(person_a);
    print_person(person_a);

    person_class person_b;
    person_b.name = "new name";
    person_b.set_age(22);

    person_class person_c("Person C Name");

    
}

void add_num(int local_int){
    cout << local_int << endl;
    local_int = 2;
}


void add_num(int *local_int){
    cout << *local_int << endl;
    *local_int = 2;
}

void passing_person(person &local_person){
    local_person.age = 21;
}

void print_person(person &local_person){
    cout << "Name: " << local_person.name << endl
         << "Age: " << local_person.age << endl
         << "location: " << local_person.location << endl
         << "zip: " << local_person.zip << endl;
}