#pragma once
#include "Iterator.h"
#include <iostream>
using namespace std;

template<typename AnyType>
class LinkedList
{
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

//Function Definitions
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
}

template<typename AnyType>
inline LinkedList<AnyType>::~LinkedList()
{
	destroy();
}

template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	for (Iterator<int>iter = begin(); iter != end(); iter++)
	{
		Node<AnyType>* temp = new Node<AnyType>(*iter);
		delete temp;
	}

	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
	delete this;
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	return Iterator<AnyType>() = m_first;
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	return Iterator<AnyType>() = m_last;
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
	for (Iterator<int>iter = begin(); iter != end(); iter++)
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

	newly->next - m_first;
	newly->previous = m_first->previous;
	m_first->previous = newly;
	newly->previous->next = newly;
	m_first = newly;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	Node<AnyType>* newly = new Node<AnyType>(value);

	newly->previous = m_last;
	newly->next = m_last->next;
	m_last->next = newly;
	newly->next->previous = newly;
	m_last = newly;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	AnyType value = (AnyType)m_first;
	Node<AnyType>* target = m_first->next;

	m_first->next->previous = nullptr;
	delete m_first;
	m_first = target;

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

	return AnyType(value);
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	int nodeIndex = 0;

	for (Iterator<int>iter = begin(); iter != end(); iter++)
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
	for (Iterator<int>iter = begin(); iter != end(); iter++)
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
	for (Iterator<int>iter = begin(); iter != end(); iter++)
	{
		cout << *iter << endl;
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
	for (Iterator<int>iter = begin(); iter != end(); iter++)
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

	for (Iterator<int>iter2 = begin(); iter2 != end(); iter2++)
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

	for (Iterator<int>iter = begin(); iter != end(); iter++)
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
	for (Iterator<int>iter = begin(); iter != end(); iter++)
	{ }
}
