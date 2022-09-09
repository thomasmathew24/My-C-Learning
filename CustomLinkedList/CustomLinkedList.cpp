#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> ll;
	ll.Push(1);
	ll.Push(2);
	ll.Push(3);
	ll.Push(4);
	ll.Push(5);

	for (int i : ll)
	{
		std::cout << "Element : " << i <<"\n";
	}

}