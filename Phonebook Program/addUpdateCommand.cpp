/*
 * addUpdateCommand.cpp
 *
 */

#include "addUpdateCommand.h"

using namespace std;

	// constructors
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, istream &inStream, ostream &outStream, undoRedo &undoRedoObject)
	:bookCommand(inStream, outStream), book(bookIn), urObject(undoRedoObject)
{	}

	// execute function to add/update the phone book
void addUpdateCommand::execute()
{
	// variables for the name, phone number, and email the user enters
	string gName = bookCommand::prompt("Enter name to add/update");
	string gNumber = bookCommand::prompt("Enter phone number");
	string gEmail = bookCommand::prompt("Enter e-mail address");

	// variables for old and new entries
	phoneBookEntry oldEntry, newEntry;

	// if the name matches a name in the phone book book, then edit the entry
	if(book.find(gName))
	{
		cout << "Updating phone book entry for " << gName << endl;

		// loop through and find the entry with the same name and set it to oldEntry
		for(phoneBookEntry entry : book)
		{
			// check if the current entry's name in the book matches the string. if it
			// does, set oldEntry to it
			if(entry.name() == gName)
				oldEntry = entry;
		}

		book.insert(gName, gNumber, gEmail);

		// loop through and find the new entry with the same name and set it to
		// newEntry
		for(phoneBookEntry entry : book)
		{
			// check if the current entry's name in the book matches the string. if it
			// does, set newEntry to it
			if(entry.name() == gName)
				newEntry = entry;
		}

		// add the updateUndoRedoCommand to stack
		urObject.addCommand(new updateUndoRedoCommand(book, oldEntry, newEntry));
	}
	else
	{
		cout << "Adding phone book entry for " << gName << endl;
		// add an entry
		book.insert(gName, gNumber, gEmail);

		// loop through and find the new entry with the same name and set it to
		// newEntry
		for(phoneBookEntry entry : book)
		{
			// check if the current entry's name in the book matches the string. if it
			// does, set newEntry to it
			if(entry.name() == gName)
				newEntry = entry;
		}

		// add the insertUndoRedoCommand to stack
		urObject.addCommand(new insertUndoRedoCommand(book, newEntry));
	}
}
