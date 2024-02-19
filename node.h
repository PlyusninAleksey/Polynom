#pragma once
template<typename T>
struct element
{
	T data;
	element* pointerNext;
};

template<typename T>
class Node
{
private:
	int size;
	element<T>* firstElement;
public:
	Node(int _size);
	Node();
	~Node();
	element<T>* getElement(int _n);
};

template<typename T>
Node<T>::Node(int _size)
{
	size = _size;
	firstElement = new element<T>;
	element<T>* oldElement = firstElement;
	for (int i = 1; i < size; i++)
	{
		element<T>* newElement = new element<T>;
		oldElement->pointerNext = newElement;
		oldElement = newElement;
	}
	oldElement->pointerNext = nullptr;
}

template<typename T>
Node<T>::Node():Node<T>::Node(1)
{}

template<typename T>
Node<T>::~Node()
{
	element<T>* nextElement = firstElement->pointerNext;
	delete firstElement;
	for (int i = 1; i < size; i++)
	{
		element<T>* currentElement = nextElement;
		nextElement = nextElement->pointerNext;
		delete currentElement;
	}
}

template<typename T>
element<T>* Node<T>::getElement(int _n)
{
	element<T>* searchElement = firstElement;
	for (int i = 1; i < _n; i++)
	{
		searchElement = searchElement->pointerNext;
	}
	return searchElement;
}

