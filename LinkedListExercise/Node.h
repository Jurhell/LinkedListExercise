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

//Function Definitions
template<typename AnyType>
inline Node<AnyType>::Node()
{
}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
}

template<typename AnyType>
inline Node<AnyType>* Node<AnyType>::next()
{
	return nullptr;
}

template<typename AnyType>
inline Node<AnyType>* Node<AnyType>::previous()
{
	return nullptr;
}

template<typename AnyType>
inline AnyType Node<AnyType>::data()
{
	return AnyType();
}
