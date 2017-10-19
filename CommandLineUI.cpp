/*
Branden Lee and Stephen Lee
CIS 22C
Fall 2017
Lab 1

Used Microsoft Visual Studio 2017

CommandLineUI class
contains the presentational and interactive interface in the command line for the user.
*/

#include <iostream>
#include <fstream>
#include "commandLineUI.h"

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
			<< "2. Open \"ExampleStrings.txt\" and examine strings." << endl
			<< "3. Push a currency" << endl
			<< "4. Pop a currency" << endl
			<< "5. Empty currencys from the stack" << endl
			<< "6. Exit Application" << endl << endl
			<< "Selection Number: ";
		// there is a bug that when you enter "test,2,3,hey" in the menu selection. 
		// The program gets stuck in an infinite loop
		cin >> menuOption;
		cout << endl;
		if (menuOption < 1 || menuOption > 6)
		{
			cout << "Your selection was not valid. Please try again. ";
		}
		else
		{
			/* please keep each sub-menu in a separate function to increase readability and prevent
			a huge blob of unorganized code. */
			if (menuOption == 1)
			{
				intDemo ();
			}
			else if (menuOption == 2)
			{
				stringDemo ();
			}
			else if (menuOption == 3)
			{
				pushStack ();
			}
			else if (menuOption == 4)
			{
				popStack ();
			}
			else if (menuOption == 5)
			{
				emptyStack ();
			}
			else if (menuOption == 6)
			{
				loopActive = false;
			}
		}
	}
}

//******************************************************
// intDemo    
//      
// This is an example of the method documentation
//******************************************************
void CommandLineUI::intDemo ()
{

}

//******************************************************
// stringDemo     
//      
// This is an example of the method documentation
//******************************************************
void CommandLineUI::stringDemo ()
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
		stackString->add (buffer);
	}
	cout << "Do you want to display the list?" << endl;
	cin >> response;
	if (response == "Yes" || response == "yes")
	{
		stackString->displayList ();
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
			stackString->remove (itemName);
			cout << "Item Count is now " << stackString->getFrequencyOf () << " nodes." << endl;
		}
		else
		{
			cout << "ERROR! Your response " << itemName << " is not in the list." << endl;
		}

	}
	cin >> repeat_response;
	cout << "All done!" << endl;
}

//******************************************************
// pushStack       
//      
// This is an example of the method documentation
//******************************************************
void CommandLineUI::pushStack ()
{

}

//******************************************************
// popStack         
//      
//******************************************************
void CommandLineUI::popStack ()
{

}

//******************************************************
// emptyStack          
//      
//******************************************************
void CommandLineUI::emptyStack ()
{

}