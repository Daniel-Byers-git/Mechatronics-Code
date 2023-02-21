#include <iostream>

// using namespace std;

// void cout(){

// }
class a {
    public:
        a(){ std::cout << "Class a constructor" << std::endl; }
    private:

    protected:
};

class b {
    public:
        b() {std::cout << "Class b constructor" << std::endl;}
};

class c: public b, public a {
    public:
        c(){ std::cout << "class c constructor" << std::endl;}
        void print(){std::cout << "print" << std::endl;}
    private:
        int private_number = 10;
        friend void NonMemberFunction();
};

void NonMemberFunction(){
    c class_test;
    std::cout << "Private Num " << class_test.private_number << std::endl;
}

int main(int counter_for_arg, char * argv[]){
    c class_var;
    NonMemberFunction();
}