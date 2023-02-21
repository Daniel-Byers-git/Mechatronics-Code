#include <iostream>
// #include ""
// Preprocessor directive = #
#define PI 3.14
// argc = argument counter
// argv = argument values
using namespace std;
// :: = scope resolution
int main(int argc, char*argv[]){
    cout << argc << endl;
    // std::cout << "First Program" << std::endl;
    // cout << "Second Line" << endl;
    // cout << argv[0] << endl;
    // cout << argv[1] << endl;
    // cout << argv[2] << endl;
    
    string val = "no";


    if ( val == "true" ){
        cout << "running in debug mode" << endl;
    } else if (val == "false" ){
        cout << "running in production mode" << endl;
    } else {
        cout << "no arg passed" << endl;
    }

    // for, while, do while
    int j = 0;
    for ( j; j < 10; j++){
        cout << j << endl;
    }
    while ( j > 0  ){
        j--;
        cout << j << endl;
    }
}