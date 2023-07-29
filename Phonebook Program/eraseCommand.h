/*
 * eraseCommand.h
 *
 */

#ifndef ERASECOMMAND_H_
#define ERASECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"
#include "undoRedo.h"
#include "eraseUndoRedoCommand.h"

class eraseCommand : public bookCommand
{
	// phone book object
	phoneBook &book;
	undoRedo &urObject;
public:
	// constructor
	eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject);

	// execute function
	virtual void execute();
};

#endif /* ERASECOMMAND_H_ */
