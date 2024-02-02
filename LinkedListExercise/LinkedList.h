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
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;

	m_first = other.m_first;
	m_last = other.m_last;

	for (Iterator<int>iter = begin(); iter != end(); ++iter)
		pushBack(*iter);
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
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{
		Node<AnyType>* temp = new Node<AnyType>(*iter);
		delete temp;
	}

	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
	delete this;
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

	return Iterator<AnyType>(m_first->previous);
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
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
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

	if (m_first == nullptr)
		m_first = newly;

	m_first->previous = newly;
	newly->next = m_first;
	m_first = newly;

	if (m_nodeCount == 0)
		m_last = newly;

	m_nodeCount++;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	Node<AnyType>* newly = new Node<AnyType>(value);

	if (m_last == nullptr)
		m_last = newly;

	m_last->next = newly;
	newly->previous = m_last;
	m_last = newly;

	if (m_nodeCount == 0)
		m_first = newly;

	m_nodeCount++;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	AnyType value = (AnyType)m_first;
	Node<AnyType>* target = m_first->next;

	m_first->next->previous = nullptr;
	delete m_first;
	m_first = target;

	m_nodeCount--;

	return AnyType(value);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	AnyType value = (AnyType)m_last;
	Node<AnyType>* target = m_last->previous;

	m_last->previous->next = nullptr;
	delete m_last;
	m_last = target;

	m_nodeCount--;

	return AnyType(value);
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	int nodeIndex = 0;

	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{
		if (index == nodeIndex)
		{
			Node<AnyType>* newly = new Node<AnyType>(value);
			Node<AnyType>* target = new Node<AnyType>(*iter);
			
			newly->previous = target->previous;
			newly->next = target;
			target->previous = newly;
			newly->previous->next = newly;

			return true;
		}
		nodeIndex++;
	}
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			Node<AnyType>* target = new Node<AnyType>(*iter);

			target->next->previous = target->previous;
			target->previous->next = target->next;
			delete target;

			return true;
		}
	}
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{
		Node<AnyType>* temp = new Node<AnyType>(*iter);
		cout << temp->data << endl;
	}
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
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{
		if (m_first->next == nullptr && m_last->previous == nullptr)
			return true;
		else
	        return false;
	}
}

template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	int nodeIndex = 0;

	for (Iterator<int>iter2 = begin(); iter2 != end(); ++iter2)
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

	for (Iterator<int>iter = begin(); iter != end(); ++iter)
		nodeIndex++;
	
	return nodeIndex;
}

template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherList)
{
	*this = otherList;
}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{ }
}
