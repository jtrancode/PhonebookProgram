/*
 * eraseUndoRedoCommand.h
 *
 */

#ifndef ERASEUNDOREDOCOMMAND_H_
#define ERASEUNDOREDOCOMMAND_H_

#include "command.h"
#include "phoneBook.h"

class eraseUndoRedoCommand : public command
{
	// phoneBook and phoneBookEntry variables
	phoneBook &book;
	phoneBookEntry entry;
public:
	// constructor
	eraseUndoRedoCommand(phoneBook &bookIn, phoneBookEntry oldEntry);

	// execute and unexecute functions
	void execute();
	void unExecute();
};

#endif /* ERASEUNDOREDOCOMMAND_H_ */
