// Demonstrate use of C++ Exceptions
// George F. Riley, Georgia Tech, Fall 2009

#include <iostream>
#include <vector>
#include <string>
#include <exception>  // Defines the exception class

using namespace std;

class A 
{
public:
  A(int i1) : i(i1) { 
    // Just for illustration, we throw an exception with char* argument
    // Since the exception occurs in the constructor, the resulting
    // object is mal-formed and cannot be accessed legally.
    throw "this is a test";
  }
  int i;
};

// LargeMemoryClass is used to quickly exhaust all available memory
class LargeMemoryClass 
{
public:
  LargeMemoryClass(){}// Nothing needed for constructor
private:
  double bigArray[0x100000]; // Takes lots of memory, used to illustrate
  // out of memory exception
};

// Class MyException shows creating your own exceptions
class MyException: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
};

//void MySub1(int k) throw(int, MyException, string)
void MySub1(int k)
{
  if (k <= 100)  throw MyException();
  if (k <= 1000) throw k;
  // throw exception not expected by caller
  throw (string("Hello | The number is too big"));
}

int main()
{
  A* a; // NULL Pointer
  try
    {
      a = new A(1); //Assign Null Pointer with member of object (class A) 
      // new = malloc
    }
  catch (const char* p)
    {
      cout << "Exception " << p << " a->i " << a->i << endl; // segfaults
      // cout << "Exception " << p << " a does not exist" << endl;
    }

  // Allocate many LargeMemoryClass objects until memory runs out
  vector<LargeMemoryClass*> largeMem; // Used to give the memory back
  LargeMemoryClass* lmc;
  while(true)
    {
      try
        {
          lmc = new LargeMemoryClass;
          largeMem.push_back(lmc);
        }
      catch (exception& e)
        {
          cout << "exception " << e.what() << endl;
          // Give back the memory
          for (unsigned i = 0; i < largeMem.size(); ++i)
            {
              delete largeMem[i];
            }
          break;
        }
    }

  // Illustrate MyException
  try
  {
    throw MyException();
  }
  catch (exception& e)
  {
    cout << e.what() << endl;
  }

  // Illustrate calling a subroutine that throws an exception

//   void MySub1(int k)
// {
//   if (k <= 100)  throw MyException();
//   if (k <= 1000) throw k;
//   // throw exception not expected by caller
//   throw (string("Hello"));
// }
int i = 100;
// try{}
try {
MySub1(i);
} catch (exception &e){
cout << "err" e.what() << endl;
}

cout <<"Beyond the error event" << endl;
  // try
  //   {
  //   //   MySub1(100);
  //     // MySub1(100);
  //     // MySub1(10000);
  //     MySub1(i);
  //   }
  // catch (exception& e)
  //   {
  //     cout << "MySub1 exception " << e.what() << endl;
  //   }
  // catch (int i)
  //   {
  //     cout << "MySub1 int exception " << i << endl;
  //     // i = 500;
  //     // cout << i << endl;
  //   }
  // catch (string msg) // what if you add string str_var
  //   {
  //     cout << "MySub1, unknown exception " << msg << endl;
  //   }
  //   catch(...){

  //   }
  //   cout << "I = " <<  i;
}


  
