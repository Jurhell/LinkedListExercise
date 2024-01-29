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

//Function Definitions
template<typename AnyType>
inline Iterator<AnyType>::Iterator()
{
}

template<typename AnyType>
inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
{

}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator++()
{
	int i = 0;
	return Iterator<AnyType>(i++);
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator--()
{
	return Iterator<AnyType>(this -= 1);
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
{
	return false;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
{
	return false;
}

template<typename AnyType>
inline AnyType Iterator<AnyType>::operator*()
{
	return AnyType();
}
