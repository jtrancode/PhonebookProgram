/*
 * redoCommand.h
 *
 *  Created on: Oct 25, 2018
 *      Author: Jolina Tran
 */

#ifndef REDOCOMMAND_H_
#define REDOCOMMAND_H_

#include "undoRedo.h"

class redoCommand : public command
{
	// undoRedo object
	undoRedo &urObject;
public:
	// constructor
	redoCommand(undoRedo &undoRedoObject);

	// execute function
	virtual void execute();
};

#endif /* REDOCOMMAND_H_ */
