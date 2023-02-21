#include <iostream>

// Memory (Addresses)
// Reference (&) and Dereference (*)
// HEX - Base 16.
// half of a byte = nibble = 4bit 
// 2^3, 2^2, 2^1, 2^0
// 0000 = 0
// 0001 = 1
// 0010 = 2
// 0011 = 3
// 0100 = 4
// 0101 = 5
// 0110 = 6
// 0111 = 7
// 1000 = 8
// 1001 = 9
// 1010 = A
// 1011 = B
// 1100 = C
// 1101 = D
// 1110 = E
// 1111 = F
// int x = 5;
// uint8_t y = 3;
// uint16_t z = 10;
// int main(){
//     std:: cout << &x << std::endl;
// }
// & "Variable Name" = Returns address of an object, variable, method, etc. (the start of the memory allocation) 
// Dereference returns the value inside of the address (or object) 
// Pointers - Is an object that has its own address somewhere in memory that stores the address of another object
// int variable = 7;
// int *pointer;
// pointer = &variable;
// cout << &pointer
// cout << pointer
// cout << *pointer
// adding pointer e.g. ponter++ for an array object reference moves to the next index address.

// Preprocessor Directives
// Allows including addition lib and code from the libraries, define variables, etc before compiler. 
// #define PI 3.14
// #define production
// #ifdef debug
    // code in here exists only when def
//#endif
// Symbol and Uses (define include ifdef ifndef endif)

// Arguments (What are they & How Are They Used/ Passed) - Values passed into a program or method to do something
// int main(int argc, char* argv[]){} -
// argc = argument counter start from 1
// argv[0] = first argument is the program name and path itself
// ./outprogram.exe argument1 argument2 "-h"
// argv = argument value array. Char aray because it is char type.
// variable arguments in c++
// void method(int par, ...)
// void method(int par, string par2)
//va_list

// Arrays, Vectors, Linked-Lists
// int array_name[6];
// int array_name[] = {0,0,0,0,0};
// Arrays are not mutable - fixed sized.
// Vector = Built in template class for dyanmic allocation of element
// Vectors and LinkedLists are part of the std namespace.
// std::vector<data_type> variable_name(number_of_elements_to_start_with);
// vector.push_back()
// pop_back()
// vectors has to have all elements next to each other contiguous. 
// What happens if a vector cannot allocated memory for the next object pushed back.
// Copys the vector to another location that has enough memory and removed the reference to the initial vector

//LinkedLists = elements do not have to be next to each other in memory because a linked list contains an
// object and point to the next element.

// Structs
// containers of different element types
// struct nameofstruct{
//    int varInStruct
//    std::string name;
//     void method()
//};
// nameofstruct.name

// Methods passing by reference, pointers, value syntax and differences
// pass by reference (&). Passed the address which means that working 
// on the passed element is making changes to the original element
// Pass by value or local declaration = makes a copy of the element to be use locally in the method
// pass by pointer = (*) - allows you to pass in a pointer that can be dereferenced to the exact element.

// Method/Function Overloading - Why, how, when
// Overload allows to have to different methods passing in different 
// number of parameters for performing different actions
// print()
// print(string name)
// print(int age)

// Classes 
// allow to define object using constructors and destructors
// Constructors - object initialized or value presetting
// Destructors - destroys the object and if needed frees memory ~class();
// Copy Constructors - passes in the object to be copied to another object
// classname(classname &){}

// Private Vs Public Vs Protected
// Private only in class, public can be accessed everywhere, protected in the specific class and derived classes 
// Operator Overloading +/-/<</etc...
//operator+(classname &a, classname &b){}
// left hand side is on the left right hand side is on the right of the + sign.

// Default constructor vs overloaded constructor 
// classname() - default constructor
// when declaring a variable do not use ();
// classname(values) - overloaded constructor
// class():var(){}

// Inheritance - Pull methods and variable from the base class into derived classes. 
// Abstract Classes - vritual keyword defined abstract classes. 
// Abstract class object cannot be used directly.

// File Input and Output Streams (fstream)
// ifstream - input file
// ofstream - output file
// fstream for both read and write.
// CIN and COUT ... ostream and istream
// fileobject >> string_variable

// Threads (pthread vs thread)
// Allows you to use multi processing or multi tasking in a program. 

// Difference Message Passing Techniques 
// What, Why and when they are used
// MPI - Computer Clusters Shared Memory, Blocking and NonBlocking Calls
// CUDA - NVidia similar concepts to MPI, allowing computation on Video Cards.
// Broker Style Messaging (MQTT, RabbitMQ, ROS) - IoT, Robot Control, ... 
// Broker style define message types and all publishers publish the same message type
// subscribers can collect the messages and do things with them.
