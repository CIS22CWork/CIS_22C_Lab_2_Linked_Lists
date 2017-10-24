/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

List
A Singly Linked List ADT which will be composed of one or more nodes.
Implement the most common linked-list behaviors as explained in class -
new list, add anywhere, delete anywhere, find anywhere,
count of items in the list, empty the list, etc.
*/

#ifndef LIST_H
#define LIST_H
#include "Node.h"

/*
To make an array have linked lists
DynamicArray<LinkedList<int>> dynamicList
That is a declaration, not a class!!!
*/
template <class T>
class List
{
protected:
	Node<T> *head;
	Node<T> *tail;
	int itemCount;
public:
	//Constructor
	List ()
	{
		head = nullptr;
		tail = nullptr;
		itemCount = 0;
	}

	////////// THIS SHOULD ALL BE PRIVATE //////////////
	////////////////////////////////////////////////////

	/** Sees whether the list is empty.
	@return True if the list is empty, or false if not. */
	bool isEmpty ()
	{
		if (!tail)
		{
			return true;
		}
		return false;
	}

	//******************************************************
	// add             
	//
	// posts to the end of the list. If successful, newEntry 
	// is stored in the list and the count of items in the 
	// list has increased by 1.
	// param newEntry The object to be added as a new entry.
	// return True if addition was successful, or false if not.    
	//******************************************************
	bool add (T newEntry)
	{
		Node<T> *newNode;
		Node<T> *currentNode;
		bool returnStatus = true;

		newNode = new Node<T> (newEntry);

		itemCount++;
		if (isEmpty ())
		{
			tail = newNode;
			head = tail;
		}
		else
		{
			currentNode = tail;

			while (currentNode->next)
				currentNode = currentNode->next;

			currentNode->next = newNode;
			head = currentNode->next;
		}
		return returnStatus;
	}

	//******************************************************
	// removeByIndex           
	//
	// removes an entry at the defined index
	// index 0=tail, SIZE-1=head 
	// list count decremented by 1 if successful.
	// returns true if addition was successful, or false if not.    
	//******************************************************
	bool removeByIndex (int indexRemove)
	{
		Node<T> *currentNode;
		Node<T> *prevNode;
		Node<T> *deletedNode;
		bool returnStatus = false;

		currentNode = tail;
		prevNode = nullptr;
		deletedNode = nullptr;

		if (indexRemove >= 0 && indexRemove < itemCount)
		{
			// loop starts from tail and moves towards head.
			for (int i = 0; i <= indexRemove; i++)
			{
				// found the index. lets remove it
				if (i == indexRemove)
				{
					returnStatus = true;
					deletedNode = currentNode;
					if (i == 0)
					{
						// deleted the tail
						if (itemCount > 0)
						{
							currentNode = currentNode->next;
						}
						tail = currentNode;
					}
					else if (i == itemCount - 1)
					{
						// deleted the head
						prevNode->next = nullptr;
						head = prevNode;
					}
					if (i > 0 && i < itemCount - 1)
					{
						// there is a previous and a next
						prevNode->next = currentNode->next;
					}
					delete deletedNode;
					itemCount--;
				}
				// next
				prevNode = currentNode;
				if (i < itemCount - 1)
				{
					currentNode = currentNode->next;
				}
			}
		}
		return returnStatus;
	}


	//******************************************************
	// removeByValue          
	//
	// removes all entries with the same value
	// list count decremented by 1 if successful.
	// returns true if addition was successful, or false if not.    
	//******************************************************
	bool removeByValue (T anEntry)
	{
		Node<T> *currentNode;
		Node<T> *prevNode;

		currentNode = tail;
		prevNode = currentNode;
		bool returnStatus = true;

		if (currentNode->value == anEntry)
		{
			currentNode = currentNode->next;
			delete tail;
			tail = currentNode;
		}
		else
		{

			while (currentNode != nullptr && currentNode->value != anEntry)
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode->value == anEntry && head->value == anEntry)
			{
				prevNode->next = currentNode->next;
				//delete currentNode;
				//delete head;
				head = prevNode;

			}
			else if (currentNode->value == anEntry)
			{
				prevNode->next = currentNode->next;
				delete currentNode;
			}
		}
		if (itemCount != 0)
		{
			itemCount--;
		}
		return returnStatus;
	}

	//******************************************************
	// getFrequencyOf         
	//
	// Counts the number of times a given entry appears in list.
	// param anEntry  The entry to be counted.
	// return  The number of times anEntry appears in the list.
	//******************************************************
	int getFrequencyOf () const
	{
		return itemCount;
	}

	//******************************************************
	// contains           
	//
	// Tests whether this list contains a given entry.
	// param anEntry  The entry to locate.
	// return  True if list contains anEntry, or false otherwise.
	//******************************************************
	bool contains (T anEntry)
	{
		Node<T> *currentNode;

		currentNode = tail;


		while (currentNode)
		{
			if (currentNode->value == anEntry)
			{
				return true;
			}
			else
			{
				currentNode = currentNode->next;
			}
		}
		return false;
	}

	//******************************************************
	// getCount           
	//
	// returns the list item count.
	//******************************************************
	int getCount ()
	{
		return itemCount;
	}

	//******************************************************
	// getValue           
	//
	// returns the value of the list node index.
	//******************************************************
	T getValue (int indexGet)
	{
		Node<T> *currentNode;
		T returnValue;

		currentNode = tail;

		if (indexGet >= 0 && indexGet < itemCount)
		{
			// loop starts from tail and moves towards head.
			for (int i = 0; i <= indexGet; i++)
			{
				// found the index. lets get it.
				if (i == indexGet)
				{
					returnValue = currentNode->value;
				}
				// next
				if (i < itemCount - 1)
				{
					currentNode = currentNode->next;
				}
			}
		}
		return returnValue;
	}

	//******************************************************
	// empty          
	//
	// returns the value of the list node index.
	//******************************************************
	bool empty ()
	{
		Node<T> *currentNode;
		Node<T> *prevNode;
		bool returnStatus = false;

		currentNode = tail;
		prevNode = nullptr;

		if (0 < itemCount)
		{
			// loop starts from tail and moves towards head.
			for (int i = 0; i < itemCount; i++)
			{
				prevNode = currentNode;
				if (i == 0)
				{
					// delete first
					tail = nullptr;
				}
				else if (i < itemCount - 1)
				{
					// next
					currentNode = currentNode->next;
					prevNode->next = nullptr;
					delete prevNode;
				}
				else
				{
					// delete last
					head = nullptr;
					returnStatus = true;
					//delete currentNode;
				}
			}
			itemCount = 0;
		}
		return returnStatus;
	}

	//******************************************************
	// Destructor          
	//
	// Removes all entries from this list.
	// post  List contains no items, and the count of items is 0.
	//******************************************************
	~List ()
	{
		Node<T> *currentNode;
		Node<T> *nextNode;

		currentNode = head;

		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}

	//******************************************************
	// operator<<        
	//******************************************************
	template <class T>
	friend std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr);

	Node<T>* getTail ()
	{
		return tail;
	}
};
#endif