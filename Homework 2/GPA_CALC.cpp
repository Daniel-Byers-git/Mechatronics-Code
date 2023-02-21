#include <iostream>
using namespace std;

double numGrade(char letter)
{
    int a = 0;
    switch(letter)
    {
        case('A'):
        {
            return 4;
        }
        case('B'):
        {
            return 3;
        }
        case('C'):
        {
            return 2;
        }
        case('D'):
        {
            return 1;
        }
        case('F'):
        {
            return a;
        }
        default:
        {
            return 0;
        }
    }
}

struct student{
    int credit[100], numCourses;
    char grade[100];
    void setGrades(int creditIN[], char gradeIN[], int numIN)
    {
        for(int i = 0; i < numIN; i++)
        {
            credit[i] = creditIN[i];
            grade[i] = gradeIN[i];
        }
        numCourses = numIN;
    };
    void addGrade  (int creditIN  , char gradeIN)
    {
        credit[numCourses] = creditIN;
        grade[numCourses] = gradeIN;
        numCourses++;
    };
    double getGPA()
    {
        double gpa, weight = 0, totcredit = 0;
        for (int i = 0; i < numCourses; i++)
        {
            weight += (credit[i] * numGrade(grade[i]));
            totcredit += credit[i];
        }
        gpa = weight / totcredit;
        return gpa;
    };
    //GPA = (credit * lettergradevalue) / summed credits
};

int main()
{
    const int numStart = 5;
    int startCredit[numStart] = {3, 4, 3, 2, 4};
    char startGrade[numStart] = {'A', 'A', 'B', 'C', 'B'};
    student me, you;
    me.setGrades(startCredit, startGrade, numStart);
    you.setGrades(startCredit, startGrade, numStart);
    me.addGrade(4, 'C'); me.addGrade(3, 'F');
    you.addGrade(2, 'B'); you.addGrade(4, 'A');
    cout << "I have a " << me.getGPA() << " GPA" << endl;
    cout << "You have a " << you.getGPA() << " GPA" <<endl;
    return 0;
}