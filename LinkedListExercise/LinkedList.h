#pragma once
#include "Iterator.h"
#include <iostream>
using namespace std;

template<typename AnyType>
class LinkedList
{
	//Declaring Constructors and Functions
public:
	LinkedList();
	LinkedList(const LinkedList<AnyType>& other);
	~LinkedList();

	void destroy();

	Iterator<AnyType> begin() const;
	Iterator<AnyType> end() const;

	AnyType first() const;
	AnyType last() const;

	bool contains(const AnyType value) const;

	void pushFront(const AnyType& value);
	void pushBack(const AnyType& value);

	AnyType popFront();
	AnyType popBack();

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);

	void print() const;
	void initialize();

	bool isEmpty() const;
	bool getData(Iterator<AnyType>& iter, int index);

	int getLength() const;

	void operator =(const LinkedList<AnyType>& otherList);
	void sort();

private:
	Node<AnyType>* m_first;
	Node<AnyType>* m_last;

	int m_nodeCount;
};

//Declaring Constructors and Deconstructors
template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	initialize();
}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	m_first = other.m_first;
	m_last = other.m_last;

	for (Iterator<int>iter = other.begin(); iter != other.end(); ++iter)
		pushBack(*iter);

	m_nodeCount = other.getLength();
}

template<typename AnyType>
inline LinkedList<AnyType>::~LinkedList()
{
	destroy();
}

/// <summary>
/// Deletes all nodes inside the LinkedList.
/// </summary>
template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	if (m_nodeCount == 0)
		return;

	for (int i = 0; i < m_nodeCount; i++)
	{
		popBack();
	}

	initialize();
}

/// <summary>
/// Returns an iterator pointing to the first node in the LinkedList.
/// </summary>
/// <returns>An Iterator pointing to the first node in the LinkedList.</returns>
template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	if (!m_first)
		return Iterator<AnyType>(nullptr);

	return Iterator<AnyType>(m_first);
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	if (!m_last)
		return Iterator<AnyType>(nullptr);

	return Iterator<AnyType>(m_last->next);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::first() const
{
	return AnyType(m_first);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::last() const
{
	return AnyType(m_last);
}

template<typename AnyType>
inline bool LinkedList<AnyType>::contains(const AnyType value) const
{
	for (Iterator<AnyType>iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
			return true;
	}
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	Node<AnyType>* newly = new Node<AnyType>(value);

	m_nodeCount++;

	if (!m_first)
	{
		m_first = newly;
		m_last = newly;
		return;
	}

	m_first->previous = newly;
	newly->next = m_first;
	m_first = newly;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	Node<AnyType>* newly = new Node<AnyType>(value);

	m_nodeCount++;

	if (!m_last)
	{
		m_last = newly;
		m_first = newly;
		return;
	}

	m_last->next = newly;
	newly->previous = m_last;
	m_last = newly;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	if (m_nodeCount == 0)
		return AnyType();

	AnyType value = m_first->data;

	m_first = m_first->next;

	if (m_first->previous)
	{
		delete m_first->previous;
		m_first->previous = nullptr;
	}

	m_nodeCount--;

	return value;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	if (m_nodeCount == 0)
		return AnyType();

	AnyType value = m_last->data;

	m_last = m_last->previous;

	if (m_last->next)
	{
		delete m_last->next;
		m_last->next = nullptr;
	}

	m_nodeCount--;

	return value;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	//Checking if the index is within the bounds of the list
	if (index < 0 || index >= m_nodeCount)
		return false;

	if (m_nodeCount == 0)
	{
		pushBack(value);
		return true;
	}

	if (index == 0)
	{
		pushFront(value);
		return true;
	}

	Node<AnyType>* newly = new Node<AnyType>(value);
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < index; i++)
	{
		if (iter->next == nullptr)
			break;

		iter = iter->next;
	}

	newly->next = iter;
	newly->previous = iter->previous;
	newly->previous->next = newly;
	iter->previous = newly;

	return true;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < m_nodeCount; i++)
	{
		if (iter == nullptr)
			return false;

		if (iter->data == value)
			break;
		
		iter = iter->next;
	}

	if (iter == m_last)
	{
		popBack();
		return true;
	}
	else if (iter == m_first)
	{
		popFront();
		return true;
	}

	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;

	delete iter;

	m_nodeCount--;

	return true;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	for (Iterator<AnyType>iter = begin(); iter != end(); ++iter)
		cout << *iter << endl;

		cout << m_nodeCount << endl;
}

template<typename AnyType>
inline void LinkedList<AnyType>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::isEmpty() const
{
	if (m_nodeCount < 1)
	{
		cout << "Empty" << endl;
		return true;
	}
	else
	{
		cout << "Occuppied" << endl;
		return false;
	}
}

template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	int nodeIndex = 0;

	for (Iterator<AnyType>iter2 = begin(); iter2 != end(); ++iter2)
	{
		nodeIndex++;
		if (index == nodeIndex)
		{
			Iterator<AnyType>* newIt = new Iterator<AnyType>(iter);
			return true;
		}
	}
	return false;
}

template<typename AnyType>
inline int LinkedList<AnyType>::getLength() const
{
	int nodeIndex = 0;

	for (Iterator<AnyType>iter = begin(); iter != end(); ++iter)
		nodeIndex++;
	
	return nodeIndex;
}

template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherList)
{
	//for loop, set every item from the list
	for (Iterator<AnyType>iter = otherList.begin(); iter != otherList.end(); ++iter)
		pushBack(*iter);
}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
	//for (Iterator<int> i = 0; i != end(); ++i)
	//{
	//	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	//	{
	//		if (iter < )
	//			;
	//	}
	//}
}
