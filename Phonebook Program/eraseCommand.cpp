/*
 * eraseCommand.cpp
 *
 */

#include "eraseCommand.h"

using namespace std;

	// constructor
eraseCommand::eraseCommand(phoneBook &bookIn, istream &inStream, ostream &outStream, undoRedo &undoRedoObject)
	:bookCommand(inStream, outStream), book(bookIn), urObject(undoRedoObject)
{	}

	// execute function to erase an entry
void eraseCommand::execute()
{
	// variable to hold the name of the entry that is to be erased
	string eraseName = bookCommand::prompt("Enter name to erase");
	// variable for the entry to be erased
	phoneBookEntry eraseEntry;

	// if entry exists in the phoneBook
	if(book.find(eraseName))
	{
		for(phoneBookEntry entry : book)
		{
			// check if the current entry's name in the book matches the string. if
			// it does, set eraseEntryEntry to it
			if(entry.name() == eraseName)
				eraseEntry = entry;
		}

		// create new eraseUndoRedoCommand cmd
		command *cmd = new eraseUndoRedoCommand(book, eraseEntry);
		// erase entry
		cmd->execute();
		// add a cmd to stack
		urObject.addCommand(cmd);

		// if the entry was erased, print out that it was erased
		cout << "Phone book entry " << eraseName << " was erased" << endl;

	}
	else
		// since entry does not exist, it was not erased
		cout << "Phone book entry " << eraseName << " was not erased" << endl;
}
