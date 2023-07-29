/*
 * updateUndoRedoCommand.h
 *
 *  Created on: Oct 25, 2018
 *      Author: Jolina Tran
 */

#ifndef UPDATEUNDOREDOCOMMAND_H_
#define UPDATEUNDOREDOCOMMAND_H_

#include "command.h"
#include "phoneBook.h"

class updateUndoRedoCommand : public command
{
	// phoneBook variables
	phoneBook &book;
	// phoneBookEntry variables for old and new entry
	phoneBookEntry oEntry, nEntry;
public:
	// constructor
	updateUndoRedoCommand(phoneBook &bookIn, phoneBookEntry oldEntry, phoneBookEntry newEntry);

	// execute and unExecute functions
	void execute();
	void unExecute();
};

#endif /* UPDATEUNDOREDOCOMMAND_H_ */
