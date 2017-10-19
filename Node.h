/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

Node
*/

#ifndef NODE_H
#define NODE_H
template <class T>
class Node
{
public:
	T value;
	Node<T> *next;

	Node (T nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}
};
#endif