#include "LinkedList.h"

int main()
{
	LinkedList<Node<int>> test;

	test.insert(10, 0);
	test.print();

	return 0;
}