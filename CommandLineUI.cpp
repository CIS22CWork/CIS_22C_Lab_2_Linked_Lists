/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

CommandLineUI class
contains the presentational and interactive interface in the command line for the user.
KEEP ALL COUT<< AND CIN>> HERE
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "commandLineUI.h"
#include "List.h"

using namespace std;

CommandLineUI::CommandLineUI (Stack<int> *stackObjInt, Stack<std::string> *stackObjString, Stack<Currency> *stackObjCurrency)
{
	stackInt = stackObjInt;
	stackString = stackObjString;
	stackCurrency = stackObjCurrency;
}

/* ******************** enterLoop ********************
the main menu UI loop
*/
void CommandLineUI::enterLoop ()
{
	cout << "Welcome to our linked list demo. ";
	bool loopActive = true;
	while (loopActive)
	{
		cout << "Please enter the number representing the menu options below:" << endl
			<< "1. Random integers in a linked list" << endl
			<< "2. Empty integers from stack" << endl
			<< "3. Open \"ExampleStrings.txt\" and examine strings." << endl
			<< "4. Empty strings from stack" << endl
			<< "5. Push a currency" << endl
			<< "6. Pop a currency" << endl
			<< "7. Empty currencys from the stack" << endl
			<< "8. Exit Application" << endl << endl
			<< "Selection Number: ";
		// there is a bug that when you enter "test,2,3,hey" in the menu selection. 
		// The program gets stuck in an infinite loop
		cin >> menuOption;
		cout << endl;
		if (menuOption < 1 || menuOption > 8)
		{
			cout << "Your selection was not valid. Please try again. ";
		}
		else
		{
			/* please keep each sub-menu in a separate function to increase readability and prevent
			a huge blob of unorganized code. */
			if (menuOption == 1) intStackDemo ();
			else if (menuOption == 2) intStackEmpty ();
			else if (menuOption == 3) stringStackDemo ();
			else if (menuOption == 4) stringStackEmpty ();
			else if (menuOption == 5) currencyStackPush ();
			else if (menuOption == 6) currencyStackPop ();
			else if (menuOption == 7) currencyStackEmpty ();
			else if (menuOption == 8) loopActive = false;
		}
	}
}

//******************************************************
// intStackDemo   
//      
// This is an example of the method documentation
//******************************************************
void CommandLineUI::intStackDemo ()
{
	int intRandom = rand () % 99999;
	stackInt->push (intRandom);
	cout << stackInt << endl << endl;
}

//******************************************************
// intStackEmpty        
//      
//******************************************************
void CommandLineUI::intStackEmpty ()
{
	stackInt->empty ();
	cout << stackInt << endl << endl;
}

//******************************************************
// stringStackDemo     
//      
// This is an example of the method documentation
//******************************************************
void CommandLineUI::stringStackDemo ()
{
	string buffer;
	ifstream read_input_file ("ExampleStrings.txt");

	string repeat_response;
	string response;
	string itemName;
	cout << "Building the linked list of strings:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		stackString->push (buffer);
	}
	cout << "Do you want to display the list?" << endl;
	cin >> response;
	if (response == "Yes" || response == "yes")
	{
		cout << stackString;
	}
	cout << "Do you want to remove an item?" << endl;
	cin >> response;
	if (response == "Yes" || response == "yes")
	{
		cout << "Enter the item name" << endl;
		cin >> itemName;
		if (stackString->contains (itemName))
		{
			cout << "Your response " << itemName << " is here.\n";
			cout << "Preparing to remove. Stand by..." << endl;
			stackString->removeByValue (itemName);
			cout << "Item Count is now " << stackString->getFrequencyOf () << " nodes." << endl;
		}
		else
		{
			cout << "ERROR! Your response " << itemName << " is not in the list." << endl;
		}

	}
	cout << "All done!" << endl << endl;
}

//******************************************************
// stringStackEmpty     
//      
//******************************************************
void CommandLineUI::stringStackEmpty ()
{
	stackString->empty ();
	cout << stackString << endl << endl;
}

//******************************************************
// currencyStackPush      
//      
// This is an example of the method documentation
//******************************************************
void CommandLineUI::currencyStackPush ()
{
	// randomly generates a derived currency class class and fills it with
	// money 0-100 whole and 0-99 fractional parts then pushes it onto the stack
	int intRandom = rand () % 4;
	if (intRandom == 0) stackCurrency->push (CurrencyDollar (rand () % 100, rand () % 99));
	else if (intRandom == 1) stackCurrency->push (CurrencyEuro (rand () % 100, rand () % 99));
	else if (intRandom == 2) stackCurrency->push (CurrencyRupee (rand () % 100, rand () % 99));
	else if (intRandom == 3) stackCurrency->push (CurrencyYen (rand () % 100, rand () % 99));
	else if (intRandom == 4) stackCurrency->push (CurrencyYuan (rand () % 100, rand () % 99));
	cout << stackCurrency << endl << endl;
}

//******************************************************
// currencyStackPop         
//      
//******************************************************
void CommandLineUI::currencyStackPop ()
{
	stackCurrency->pop ();
	cout << stackCurrency << endl << endl;
}

//******************************************************
// currencyStackEmpty      
//      
//******************************************************
void CommandLineUI::currencyStackEmpty ()
{
	stackCurrency->empty ();
	cout << stackCurrency << endl << endl;
}

//******************************************************
// operator<<        
//******************************************************
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{
	// Since operator<< is a friend of the List class, we can access
	// it's members directly.
	int itemCount = 0;
	Node<T> *currPtr = ListPtr->getTail ();
	while (currPtr != nullptr)
	{
		itemCount++;
		foo << itemCount << ". " << currPtr->value << endl;
		currPtr = currPtr->next;
	}
	return foo;
}