/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

Node
*/

template <class T>
class ListNode
{
public:
	T value;
	ListNode<T> *next;

	ListNode(T nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}
};