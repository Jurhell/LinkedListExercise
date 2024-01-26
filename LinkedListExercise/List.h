#pragma once
#include "Iterator.h"

template<typename AnyType>
class List
{
public:
	List();
	List(const List<AnyType>& other);
	~List();

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

	void operator =(const List<AnyType>& otherList);
	void sort();

private:
	Node<AnyType>* m_first, m_last;
	int m_nodeCount;
};