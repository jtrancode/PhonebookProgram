/*
 * printCommand.cpp
 *
 */

#include "printCommand.h"

using namespace std;

	// constructor
printCommand::printCommand(phoneBook &bookIn, istream &inStream, ostream &outStream)
	:bookCommand(inStream, outStream), book(bookIn)
{	}

	// execute function to print contents of phone book
void printCommand::execute()
{
	// if phone book is not empty
	if(book.size() > 0)
		// call phoneBook's print function
		book.print(out);
	else
		// otherwise print that the phone book is empty
		prompt("The phone book is empty");
}
