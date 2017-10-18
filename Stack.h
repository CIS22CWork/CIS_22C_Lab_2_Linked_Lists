/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

Stack
*/

template <class T>
class ListInterface : public NumberList<T>
{
private:
	int itemCount = 0;
public:

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
		ListNode<T> *newNode;
		ListNode<T> *currentNode;
		bool returnStatus = true;

		newNode = new ListNode<T>(newEntry);

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
		ListNode<T> *currentNode;
		ListNode<T> *prevNode;

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
		ListNode<T> *currentNode;

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
	//To display the entire linked list
	void displayList()
	{
		itemCount = 0;
		ListNode<T> *currPtr = tail;
		while (currPtr != nullptr)
		{

			itemCount++;
			cout << "Node " << "value ";
			cout << "itemCount " << itemCount << "= " << currPtr->value << endl;
			currPtr = currPtr->next;
		}

	}
};