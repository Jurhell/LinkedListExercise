#pragma once
#include "Node.h";

template<typename AnyType>
class Iterator
{
	//Declaring Constructors and Overloads
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

//Function Definitions

//Declaring Constructors 
template<typename AnyType>
inline Iterator<AnyType>::Iterator()
{
	m_current = nullptr;
}

template<typename AnyType>
inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
{
	m_current = node;
}

/// <summary>
/// Overloads the ++ operator to increment the current node pointer.
/// </summary>
/// <returns>The pointer for the next node.</returns>
template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator++()
{
	Iterator<AnyType> iter = Iterator<AnyType>(m_current->next);
	return iter;
}

/// <summary>
/// Overloads the -- operator to decrement the current node pointer.
/// </summary>
/// <returns>The pointer for the previous node.</returns>
template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator--()
{
	Iterator<AnyType> iter = Iterator<AnyType>(m_current->previous);
	return iter;
}

/// <summary>
/// Overloads the == operator to return if two nodes are the same.
/// </summary>
/// <typeparam name="AnyType"></typeparam>
/// <param name="iter">The iterator pointing at the node that will be compared.</param>
/// <returns>A boolean saying both nodes are the same.</returns>
template<typename AnyType>
inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
{
	return m_current == iter.m_current;
}

/// <summary>
/// Overloads the != operator to return if two nodes are not the same.
/// </summary>
/// <typeparam name="AnyType"></typeparam>
/// <param name="iter">The iterator pointing at the node that will be compared.</param>
/// <returns>A boolean saying the two nodes are not the same.</returns>
template<typename AnyType>
inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
{
	return m_current != iter.m_current;
}

/// <summary>
/// Overloads the dereference operator to get the data from a node the iterator is pointing at.
/// </summary>
/// <returns>The data from the current node.</returns>
template<typename AnyType>
inline AnyType Iterator<AnyType>::operator*()
{
	//if (m_current == nullptr)
	//	m_current = ;

	return m_current->data;
}
