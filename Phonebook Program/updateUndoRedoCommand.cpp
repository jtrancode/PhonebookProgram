/*
 * updateUndoRedoCommand.cpp
 *
 */

#include "updateUndoRedoCommand.h"

using namespace std;

	// constructor
updateUndoRedoCommand::updateUndoRedoCommand(phoneBook &bookIn, phoneBookEntry oldEntry, phoneBookEntry newEntry)
	:book(bookIn), oEntry(oldEntry), nEntry(newEntry)
{	}

	// execute and unExecute functions
void updateUndoRedoCommand::execute()
{
	// redo update with new entry
	book.insert(nEntry);
}
void updateUndoRedoCommand::unExecute()
{
	// undo update with old entry
	book.insert(oEntry);
}


