#include <iostream>
#include <fstream> //file stream - char
#include <string> 

using namespace std;

int main(int number_of_arguments, char *argument_array[]){
    cout << "Number of arguments" << number_of_arguments << endl;
    // *** Cout is an object of type output stream (char array stream for sending data out)
    cout << "File IO" << endl;
    
    // *** String custom class for combining characters into a string (also char array) 
    // *** String is not the same as an ostream object, but similar concept 
    // *** string is indexable using square brackets string[1] will give you the char in index 1.
    string item1, item2, item3;
    
    // *** CIN is another object just like cout, but an input stream (istream) object
    // *** CIN breaks on /r /t /n space
    // *** The code below will require 3 input separate by a space new line or tab
    // cin >> item >> item2 >> item3;
    // cout << item << endl;
    // cout << item2 << endl;
    // cout << item3 << endl;
    string getLineStr;
    
    // *** C command used to clear the console input buffer to remove any left over items. 
    // *** CIN buffer will maintain entries not set to a variable. 
    // fflush(stdin);
    
    // *** getline is a method used to pull in the entire line as a string (up to the next line \n)
    // getline(cin, getLineStr);
    // cout << getLineStr << endl;
    
    // *** Like cout and cin from include <iostream> class, the file input and output use 
    // *** an ostream and istream object. The file class header is called fstream
    // *** an ofstream object is used for outputting to a file
    // *** an ifstream object is used for inputting from a file
    // *** you can use the overloaded constructor for inputting the path and file name directly
    // *** or declare object and use the open method for opening the file
    // ofstream outputVariableName("OutputFile.txt");
    // outputVariableName.open("OutputFile.txt");
    
    // *** Writting to a file is similar to the cout ostream
    // outputVariableName << 16 <<"\t" << 18 << endl;
    
    // *** File objects must be closed to ensure releasing handle to it
    // outputVariableName.close();
    
    // *** Input stream example below
    // ifstream inputStream;
    // inputStream.open("OutputFile.txt");
    // *** Both input and output file streams can pass additional arguments listed at the end of this file
    // *** Similarly an fstream can be used to write and read from files simulatenously.
    // *** ios_base:in = input, ios_base:out = output, ios_base:app = append, ios_base:ate = at the end of file (creates a new file) 
    // fstream fileVarName("OutputFile.txt", std::ios_base::in | std::ios_base::out | std::ios_base::app);
    fstream fileVarName("OutputFile.txt", std::ios_base::out | std::ios_base::ate);
    // *** Reading in from a file is the same as cin
    // int var1, var2;
    // inputStream >> var1 >> var2;
    // cout << "Var1: " << var1 << " var2: " << var2;
    // inputStream.close();

    fileVarName << 12 << "\t";
    fileVarName << 14 << "\t";
    fileVarName.close();

    ifstream inputVarName;
    inputVarName.open("OutputFile.txt", std::ios_base::in);
    getline(inputVarName, getLineStr);
    cout << getLineStr << endl;
    inputVarName.close();

    inputVarName.open("OutputFile.txt", std::ios_base::in);
    // *** Can read an entire file using the following methods and more
    while(getline(inputVarName, getLineStr)){
        cout << getLineStr << endl;
    }
    inputVarName.close();
    
    inputVarName.open("OutputFile.txt", std::ios_base::in);
    // *** if you know the format of the file you can read individual values into variable
    // string item1, item2;
    while(inputVarName){
        inputVarName >> item1 >> item2;
        cout << item1 + item2 << endl;
    }
    inputVarName.close();
    inputVarName.open("OutputFile.txt", std::ios_base::in);
    // *** if you know the format of the file you can read individual values into variable
    while(inputVarName >> item1 >> item2){
        cout << item1 + item2 << endl;
    }
    inputVarName.close();
    inputVarName.open("OutputFile.txt", std::ios_base::in);
    // *** or get the entire line and split it using tokenize
    while(inputVarName){
        string line;
        getline(inputVarName, line);
        cout << line << endl;
    }

    
    // *** cannot write once object is closed.
    // outputStreamVar << "The end"<<endl;
}

// Concepts
// string
// cin;
// fflush(stdin) vs cin.ignore();
// fstream
// ifstream
// ofstream
// getline(outputStreamVar, line)

// app	(append) Set the stream's position indicator to the end of the stream before each output operation.
// ate	(at end) Set the stream's position indicator to the end of the stream on opening.
// binary	(binary) Consider stream as binary rather than text.
// in	(input) Allow input operations on the stream.
// out	(output) Allow output operations on the stream.
// trunc	(truncate) Any current content is discarded, assuming a length of zero on opening.