/*
 * bookCommand.cpp
 *
 */

#include "bookCommand.h"

using namespace std;

	// constructor
bookCommand::bookCommand(istream &inStream, ostream &outStream)
	:in(inStream), out(outStream)
{	}

	// function prints whatever string is given
void bookCommand::showPrompt(string input) const
{
	out << input << endl;
}
	// function to return user input
string bookCommand::prompt(string info)
{
	// print info
	showPrompt(info);

	// variable to hold string
	string hold;
	// puts whatever user inputs into hold
	getline(in, hold);

	// return whatever user input as a string
	return hold;
}
