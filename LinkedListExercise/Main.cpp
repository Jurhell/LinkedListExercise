#include "LinkedList.h"

int main()
{
	LinkedList<int> test = LinkedList<int>();
	
	test.pushBack(5);
	test.pushFront(4);
	test.pushFront(3);
	test.pushFront(2);
	test.pushFront(1);

	test.destroy();

	test.print();

	return 0;
}