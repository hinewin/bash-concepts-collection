// main: coordinates input.cpp, concat.cpp,  output.cpp
// the program asks the user for their first and last names,
// concatenate them to the string hello, and prints the string

#include "concat.h"
#include "input.h"
#include "output.h"

int main ()
{
	std::string s1, s2, outStr;

	getInput(s1, s2);
	outStr = concat(s1, s2);
	output(outStr);	
	
	return 0;
}
