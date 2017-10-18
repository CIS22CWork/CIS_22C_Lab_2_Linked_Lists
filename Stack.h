/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

Stack
*/

template <class T>
class Stack : public List<T>
{
public:

	bool pop(T anEntry)
	{
		return remove(anEntry);
	}
	bool push(T newEntry)
	{
		return add(newEntry);
	}
	bool isempty()
	{
		return isEmpty()
	}
	//To display the entire linked list
	void displayList()
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