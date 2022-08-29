#include <iostream>
#include "Array.h"


int main()
{
	Array<std::string, 2> names;
	names[0] = "Thomas";
	names[1] = "Mathew";

	for (std::string name : names)
		std::cout << name;

	//return 0;
}