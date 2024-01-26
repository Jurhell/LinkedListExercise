#pragma once

template<typename AnyType>
class Node
{
public:
	Node();
	Node(AnyType value);

	Node<AnyType>* next();
	Node<AnyType>* previous();

	AnyType data();
};