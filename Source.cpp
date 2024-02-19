#include <iostream>
#include "node.h"

void main()
{
	Node<int> node(3);
	node.getElement(1)->data = 5;
	node.getElement(2)->data = 2;
	node.getElement(3)->data = 3;
	std::cout << node.getElement(2)->data;
}