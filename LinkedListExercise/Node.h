#pragma once

template<typename AnyType>
class Node
{
public:
	Node();
	Node(AnyType value);

	Node<AnyType>* next;
	Node<AnyType>* previous;

	AnyType data();
};

//Function Definitions
template<typename AnyType>
inline Node<AnyType>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
}

template<typename AnyType>
inline AnyType Node<AnyType>::data()
{
	return AnyType();
}
