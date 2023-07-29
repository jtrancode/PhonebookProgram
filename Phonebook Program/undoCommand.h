/*
 * undoCommand.h
 *
 *  Created on: Oct 25, 2018
 *      Author: Jolina Tran
 */

#ifndef UNDOCOMMAND_H_
#define UNDOCOMMAND_H_

#include "undoRedo.h"

class undoCommand : public command
{
	// undoRedo object
	undoRedo &urObject;
public:
	// constructor
	undoCommand(undoRedo &undoRedoObject);

	// execute function
	virtual void execute();
};

#endif /* UNDOCOMMAND_H_ */
