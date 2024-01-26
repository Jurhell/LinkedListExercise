#pragma once
#include "Node.h";

template<typename AnyType>
class Iterator
{
public:
	Iterator();
	Iterator(Node<AnyType>* node);

	Iterator<AnyType> operator ++();
	Iterator<AnyType> operator --();

	const bool operator == (const Iterator<AnyType>& iter);
	const bool operator != (const Iterator<AnyType>& iter);

	AnyType operator *();

private:
	Node<AnyType>* m_current;
};