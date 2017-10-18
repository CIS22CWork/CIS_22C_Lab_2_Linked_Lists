/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

List
*/

template <class T>
class List
{
protected:
	Node<T> *head;
	Node<T> *tail;
public:
	//Constructor
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty();
	bool add(T);
	bool remove(T);
	int getFrequencyOf();
	bool contains(T);

	//Destructor
	/*Removes all entries from this list.
	post  List contains no items, and the count of items is 0. */
	~List()
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
};