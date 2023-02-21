#include "Course.h"

void Course:: display()
{
    cout << subject << " " << courseNum << endl;
}

DirectedResearch:: DirectedResearch(string S, int N, string M)
{
    subject = S;
    courseNum = N;
    mentor = M;
}

void DirectedResearch:: display()
{
    Course::display();
    cout << "Mentor: " << mentor << endl;
}

Laboratory:: Laboratory(string S, int N, int L)
{
    subject = S;
    courseNum = N;
    labFee = L;
}

void Laboratory:: display()
{
    Course::display();
    cout << "Lab Fee: $" << labFee << endl;
}