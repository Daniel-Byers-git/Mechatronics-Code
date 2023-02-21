#include "Course.h"

int main ()
{
    Course Statics ("ENGR", 2214);
    DirectedResearch Research ("MTRE", 4490, "Dr. Guerra");
    Laboratory ControlsLab ("MTRE", 4002, 50);
    Statics.display();
    cout << endl;
    Research.display();
    cout << endl;
    ControlsLab.display();
    return 0;
}