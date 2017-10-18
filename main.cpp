/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

main
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Node.h"
#include "List.h"
#include "Stack.h"
#include "currency.h"

using namespace std;

int main()
{
	ListInterface<string> nodeList;
	string buffer;
	ifstream read_input_file("Words.txt");

	string repeat_response;
	string response;
	string itemName;
	cout << "Building the linked list of strings:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		nodeList.add(buffer);
	}
	exit;
	cout << "Do you want to display the list?" << endl;
	cin >> response;
	if (response == "Yes" || response == "yes")
	{
		nodeList.displayList();
	}
	cout << "Do you want to remove an item?" << endl;
	cin >> response;
	if (response == "Yes" || response == "yes")
	{
		cout << "Enter the item name" << endl;
		cin >> itemName;
		if (nodeList.contains(itemName))
		{
			cout << "Your response " << itemName << " is here.\n";
			cout << "Preparing to remove. Stand by..." << endl;
			nodeList.remove(itemName);
			cout << "Item Count is now " << nodeList.getFrequencyOf() << " nodes." << endl;
			cout << "Press any key and Enter." << endl;
		}
		else
		{
			cout << "ERROR! Your response " << itemName << " is not in the list." << endl;
			cout << "Press any key and Enter." << endl;
		}

	}
	cin >> repeat_response;
	cout << "All done!" << endl;
	system("pause");
	return 0;
}



/*
To make an array have linked lists

DynamicArray<LinkedList<int>> dynamicList

That is a declaration, not a class!!!




*/