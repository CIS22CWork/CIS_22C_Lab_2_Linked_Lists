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

#include "Stack.h"
#include "Currency.h"
#include "CommandLineUI.h"

using namespace std;

int main ()
{
	Stack<int> stackInt;
	Stack<string> stackString;
	Stack<Currency> stackCurrency;
	CommandLineUI UI (&stackInt, &stackString, &stackCurrency);
	// start the UI
	UI.enterLoop ();

	//comment out the next line before compiling final .exe and submitting to the teacher
	system ("pause");
	return 0;
}