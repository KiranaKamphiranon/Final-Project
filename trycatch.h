#include <exception>
#include <iostream>
#include <iomanip>
using namespace std;

class my_cin: public exception 
{ 
  public:
    virtual const char* what() const throw()
    { 
      cout<<endl;
			return "\tIt\'s not a number";
    } 
};

class check_mycin:  public exception 
{ 
  public:
    virtual const char* what() const throw()
    { 
      cout<<endl;
			return "\tInput again!!! -> ";
    } 
};