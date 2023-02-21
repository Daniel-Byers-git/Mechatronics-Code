#include <iostream>
#include <string>
using namespace std;

class Course 
{
    protected: 
        string subject;
        int courseNum;
    public:
        Course() : subject(), courseNum() {}
        Course(string S, int N) : subject(S), courseNum(N) {}
        void display();
};

class DirectedResearch : public Course 
{
    public:
        DirectedResearch(string S, int N, string M);
        string mentor;
        void display();
};

class Laboratory : public Course
{
    public:
    Laboratory(string S, int N, int L);
        int labFee;
        void display();
};