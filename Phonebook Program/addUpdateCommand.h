/*
 * addUpdateCommand.h
 *
 */

#ifndef ADDUPDATECOMMAND_H_
#define ADDUPDATECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"
#include "undoRedo.h"
#include "insertUndoRedoCommand.h"
#include "updateUndoRedoCommand.h"

class addUpdateCommand : public bookCommand
{
	// phone book object
	phoneBook &book;
	undoRedo &urObject;
public:
	// constructors
	addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject);

	// execute function
	virtual void execute();
};

#endif /* ADDUPDATECOMMAND_H_ */
