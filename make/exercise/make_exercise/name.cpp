// name.cpp

// user defined header files
#include "name.h" 
#include "printing.h"

string getName()
{
	string name;
	printGreeting();    // printGreeting is from printing.h
	getline(cin, name);  
	return name;
}
