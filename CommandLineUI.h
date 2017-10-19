#include <sstream>
#include <limits>
#include "Currency.h"
#include "Stack.h"

class CommandLineUI
{
private:
	Stack<int>* stackInt;
	Stack<std::string>* stackString;
	Stack<Currency>* stackCurrency;
	int menuOption;
	int currentMenu;
public:
	CommandLineUI (Stack<int> *stackObjInt, Stack<std::string> *stackObjString, Stack<Currency> *stackObjCurrency);
	void enterLoop ();
	void intDemo ();
	void stringDemo ();
	void pushStack ();
	void popStack ();
	void emptyStack ();
};