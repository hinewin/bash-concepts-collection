// hello.cpp

// standard library
#include <iostream>
#include <string>
using namespace std;

// user defined header files
#include "name.h"
#include "printing.h"

int main ()
{
	string name;

	name = getName();   // getName is in name.h
	printHello(name);   // printHello is in printing.h
	
	return 0;
}
