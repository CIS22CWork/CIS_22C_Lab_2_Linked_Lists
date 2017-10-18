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
	int itemCount;
public:
	//Constructor
	List()
	{
		head = nullptr;
		tail = nullptr;
		itemCount = 0;
	}

	////////// THIS SHOULD ALL BE PRIVATE //////////////
	////////////////////////////////////////////////////

	/** Sees whether the list is empty.
	@return True if the list is empty, or false if not. */
	bool isEmpty()
	{
		if (!tail)
		{
			return true;
		}
		return false;
	}

	/**Adds a new entry to the list.
	post  If successful, newEntry is stored in the list and
	the count of items in the list has increased by 1.
	param newEntry The object to be added as a new entry.
	return True if addition was successful, or false if not. */
	bool add(T newEntry)
	{
		Node<T> *newNode;
		Node<T> *currentNode;
		bool returnStatus = true;

		newNode = new Node<T>(newEntry);

		itemCount++;
		if (isEmpty())
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

	/*Removes one occurrence of a given entry from this list, if possible.
	post  If successful, anEntry has been removed from the list and the count of
	items in the list has decreased by 1.
	param anEntry  The entry to be removed.
	return  True if removal was successful, or false if not.*/
	bool remove(T anEntry)
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

	/*Counts the number of times a given entry appears in list.
	param anEntry  The entry to be counted.
	return  The number of times anEntry appears in the list. */
	int getFrequencyOf() const
	{
		return itemCount;
	}

	/*Tests whether this list contains a given entry.
	param anEntry  The entry to locate.
	return  True if list contains anEntry, or false otherwise. */
	bool contains(T anEntry)
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