#include "LinkedList.h"

int main()
{
	LinkedList<int> test = LinkedList<int>();
	
	test.pushBack(7);
	test.pushFront(5);
	test.pushFront(1);
	test.pushFront(2);

	test.print();

	return 0;
}