#include <iostream>
#include <vector>
// #include ""
// Preprocessor directive = #
#define PI 3.14
// argc = argument counter
// argv = argument values
using namespace std;
// :: = scope 

// void add_two_num(int, int);
void add_two_num(int &, int &);
// void add_two_num(int *, int *);

int main(int argc, char*argv[]){
    float array_one[5];
    float array_two[] = {1,4,5};
    array_one[0] = 10.5;
    array_one[1] = 10.5;
    array_one[2] = 10.5;
    array_one[3] = 10.5;
    array_one[4] = 10.5;

    std::vector<float> first_vector(0);
    first_vector.push_back(10.5);
    first_vector.push_back(7.5);
    first_vector.push_back(3);
    // first_vector.push_back(3);
    first_vector.pop_back();
    // std::cout << "Print" << endl;

    // for (int i = 0; i < first_vector.size(); i++){
    //     cout << first_vector[i] << endl;
    //     cout << first_vector.at(i) << endl;
    // }

    // for (auto &it : first_vector){
    //     cout << it << endl;
    // }

    // for (vector<float>::iterator it = first_vector.begin(); it != first_vector.end(); it++){
    //     cout << *it << endl;
    // }

    int var_one = 10;

    cout << &var_one << endl;
    cout << var_one << endl;

    int *pointer_var = &var_one;

    cout << pointer_var << endl;
    cout << &pointer_var << endl;
    cout << *pointer_var << endl;

    int var_a = 2;
    int var_b = 3;
    add_two_num(var_a, var_b);
    cout << var_a << endl << var_b << endl;
}
// // 
// void add_two_num(int num1, int num2){
//     num1 = 10;
//     num2 = 5;
//     cout << num1 + num2 << endl;
// }

void add_two_num(int &num1, int &num2){
    num1 = 10;
    num2 = 5;
    cout << num1 + num2 << endl;
}

// void add_two_num(int *num1, int *num2){
//     *num1 = 10;
//     *num2 = 5;
//     cout << *num1 + *num2 << endl;
// }