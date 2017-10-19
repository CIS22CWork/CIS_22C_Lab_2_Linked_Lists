/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

Stack
A Stack ADT derived from a singly linked list which will implement 
the most common Stack operations like push, pop, isempty etc. 
and only expose them.
*/

#ifndef STACK_H
#define STACK_H
#include "List.h"

template <class T>
class Stack : public List<T>
{
public:
	Stack ()
	{

	}

	//******************************************************
	// pop        
	//
	// removes the top element     
	//******************************************************
	bool pop ()
	{
		return removeByIndex (getCount () - 1);
	}

	//******************************************************
	// push        
	//
	// inserts element at the top     
	//******************************************************
	bool push (T newEntry)
	{
		return add (newEntry);
	}

	//******************************************************
	// isempty        
	//
	// checks whether the underlying container is empty     
	//******************************************************
	bool isempty ()
	{
		return isEmpty ()
	}

	//******************************************************
	// size         
	//
	// returns the number of elements     
	//******************************************************
	int size ()
	{
		return getCount ();
	}

	//******************************************************
	// top        
	//
	// accesses the top element     
	//******************************************************
	T top ()
	{
		return getValue(getCount () - 1);
	}


	//To display the entire linked list
	void displayList ()
	{
		itemCount = 0;
		Node<T> *currPtr = tail;
		while (currPtr != nullptr)
		{

			itemCount++;
			cout << "Node " << "value ";
			cout << "itemCount " << itemCount << "= " << currPtr->value << endl;
			currPtr = currPtr->next;
		}

	}
};

#endif