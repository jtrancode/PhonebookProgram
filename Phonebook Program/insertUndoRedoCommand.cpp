/*
 * insertUndoRedoCommand.cpp
 *
 */

#include "insertUndoRedoCommand.h"

using namespace std;

	// constructor
insertUndoRedoCommand::insertUndoRedoCommand(phoneBook &bookIn, phoneBookEntry newEntry)
	:book(bookIn), entry(newEntry)
{	}

	// execute and unExecute functions
void insertUndoRedoCommand::execute()
{
	// redo insert
	book.insert(entry);
}
void insertUndoRedoCommand::unExecute()
{
	// undo insert aka erase
	book.erase(entry.name());
}
