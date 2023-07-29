/*
 * eraseUndoRedoCommand.cpp
 *
 */

#include "eraseUndoRedoCommand.h"

using namespace std;

	// constructor
eraseUndoRedoCommand::eraseUndoRedoCommand(phoneBook &bookIn, phoneBookEntry oldEntry)
	:book(bookIn), entry(oldEntry)
{	}

	// execute and unexecute functions
void eraseUndoRedoCommand::execute()
{
	// redo erase
	book.erase(entry.name());
}
void eraseUndoRedoCommand::unExecute()
{
	// undo erase aka insert
	book.insert(entry);
}
