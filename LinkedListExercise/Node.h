#pragma once

template<typename AnyType>
class Node
{
	//Declaring Constructors and Variables
public:
	Node();
	Node(AnyType value);

	Node<AnyType>* next;
	Node<AnyType>* previous;

	AnyType data;
};

//Declaring Constructors
template<typename AnyType>
inline Node<AnyType>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
	next = nullptr;
	previous = nullptr;
	data = value;
}

