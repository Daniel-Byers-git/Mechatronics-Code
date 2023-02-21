// What is a preprocessor directive?
    // A: Commands to be done before the code compiles
#include <iostream>
#include <bitset>
#include <vector>
#define PI 3.14
//What is a namespace?
    //A: A decleration of using a certain library
using namespace std;

//What are arguments?
    //A: Extra info passed into code at compiling
int main(int a, char *argumentValues[]){

    //Array Declaration
    int array_one[] = {10, 20, 30};

    //Declare New Array
    int array_two[3];
    
    array_two[0] = -10;
    array_two[1] = -20;
    array_two[2] = -30;
    //array_two[3] = -40; no no

    // VARIABLE Initialization, Condition, Variable Update
    std::cout << " Array Two " << endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Address: " << &array_two[i] << std::endl;
        //What do you expect to see? 
            //A: The Hexidecimal memory addresses for all four values of array_two
        std::cout << "Value: " << array_two[i] << std::endl;
        //What do you expect to see?
            //A: -10, -20, -30, (doesn't get too index 3)
        std::cout << "Binary: " << std::bitset<32>( array_two[i] ) << std::endl;
        //What do you expect to see?
            //A: Binary representaion of "value"
        std::cout << "Hex: " << std::hex << array_two[i] << std::dec << std::endl;
        //What do you expect to see?
            //A: Hexidecimal representation of "value"
    }

    std::cout << " Array One " << endl; 
    int j = 0;
    while (j < 3) {
        std::cout << &array_one[j] << std::endl;
        //What do you expect to see?
            //The hexidecimal memory address for the 3 values of array_one
        std::cout << array_one[j] << std::endl;
        //What do you expect to see?
            // 10, 20, 30 
        j++; // same thing as j = j + 1;
    }
    std::cout << " Did array print out correctly? Why or Why Not? " << endl; 
        //A: array_one did not print out correctly. It seems like memory from array_two
        //   was printed for the first address and value. 


    //Pointer and Reference Practice Complete The Code:
    std::cout << "Pointer Understanding" << endl;

    int integer_one = 5;
    //replace _ with the correct code
    std::cout << "The address of integer_one is: " << &integer_one << std::endl;

    int* integer_pointer = &integer_one;
    //Please correct the code below to print the address value
    std::cout << "Address of the pointer: " << &integer_pointer << std::endl;
    std::cout << "Value inside the pointer: " << integer_pointer << std::endl;
    //Please correct the code below to print the address value
    std::cout << "Value at the pointer address: " << *integer_pointer << std::endl;

    int array_example[3] = {0, 1, 2};
    int* array_pointer = array_example;
    //Why is there no reference (&) in front of the array?
        //A: It is automatically assigned to the first index's memory
    std::cout << "Pointer In An Array" << std::endl;
    std::cout << "Address of the array pointer: " << &array_pointer << std::endl;
    std::cout << "Value inside the array pointer: " << array_pointer << std::endl;
    std::cout << "Value at the array pointer address: " << *array_pointer << std::endl;
    array_pointer++;
    std::cout << "Array Pointer ++" << std::endl;
    std::cout << "Address of the array pointer: " << &array_pointer << std::endl;
    std::cout << "Value inside the array pointer: " << array_pointer << std::endl;
    std::cout << "Value at the array pointer address: " << *array_pointer << std::endl;
    array_pointer++;
    std::cout << "Array Pointer ++" << std::endl;
    std::cout << "Address of the array pointer: " << &array_pointer << std::endl;
    std::cout << "Value inside the array pointer: " << array_pointer << std::endl;
    std::cout << "Value at the array pointer address: " << *array_pointer << std::endl;
    array_pointer--;
    std::cout << "Array Pointer --" << std::endl;
    std::cout << "Address of the array pointer: " << &array_pointer << std::endl;
    std::cout << "Value inside the array pointer: " << array_pointer << std::endl;
    std::cout << "Value at the array pointer address: " << *array_pointer << std::endl;

    std::cout << "Can you access the array pointer with []???" << std::endl;
        //A: Yes. But it starts index at current location. 
    std::cout << "Value at the array pointer address: " << array_pointer[1] << std::endl;
    std::cout << "If yes, does the index start at zero in our example? "
                 " \n or from the current location?" << std::endl;         
}


    