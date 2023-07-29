/*
 * undoRedo.h
 *
 *  Created on: Oct 25, 2018
 *      Author: Jolina Tran
 */

#ifndef UNDOREDO_H_
#define UNDOREDO_H_

#include "stack.h"

class undoRedo
{
	stack undoStack;
	stack redoStack;
public:
	// constructor
	undoRedo();
	// destructor
	virtual ~undoRedo();

	// function that will add a new command onto undo stack
	virtual void addCommand(command *newCommand);
	// note that undoRedo will delete the command in its destructor

	// undo and redo stack functions that move commands between stacks
	virtual void undo();
	virtual void redo();
};

#endif /* UNDOREDO_H_ */
