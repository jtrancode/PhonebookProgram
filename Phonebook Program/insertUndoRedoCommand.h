/*
 * insertUndoRedo.h
 *
 */

#ifndef INSERTUNDOREDOCOMMAND_H_
#define INSERTUNDOREDOCOMMAND_H_

#include "command.h"
#include "phoneBook.h"

class insertUndoRedoCommand : public command
{
	// phoneBook and phoneBookEntry variables
	phoneBook &book;
	phoneBookEntry entry;
public:
	// constructor
	insertUndoRedoCommand(phoneBook &bookIn, phoneBookEntry newEntry);

	// execute and unExecute functions
	void execute();
	void unExecute();
};

#endif /* INSERTUNDOREDOCOMMAND_H_ */
