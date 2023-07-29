/*
 * undoRedo.cpp
 *
 */

#include "undoRedo.h"
#include "memoryLeak.h"

using namespace std;

	// constructor
undoRedo::undoRedo()
	:undoStack(), redoStack()
{	}
	// destructor
undoRedo::~undoRedo()
{
	// while the undoStack isn't empty, start deleting stuff
	while(!undoStack.empty())
	{
		// delete the command that's on the top of the undo stack
		delete undoStack.top();

		// pop off the top entry
		undoStack.pop();
	}

	// while the redoStack isn't empty, start deleting stuff
	while(!redoStack.empty())
	{
		// delete the command that's on the top of the redo stack
		delete redoStack.top();

		// pop off the top entry
		redoStack.pop();
	}
}

	// add newCommand onto undo stack
void undoRedo::addCommand(command *newCommand)
{
	undoStack.push(newCommand);
}

	// if undo stack is not empty, execute unExecute() function and move the command at
	// the top of the undo stack to redo stack
void undoRedo::undo()
{
	if(!undoStack.empty())
	{
		// call unExecute()
		undoStack.top()->unExecute();

		// push the entry that's on top of the undoStack to the redo stack
		redoStack.push(undoStack.top());

		// pop off the top entry in the undo stack
		undoStack.pop();
	}
}
	// if redo stack is not empty, execute unExecute() function and move the command at
	// the top of the redo stack to undo stack
void undoRedo::redo()
{
	if(!redoStack.empty())
	{
		// call unExecute()
		redoStack.top()->execute();

		// push the entry that's on top of the redoStack to the undo stack
		undoStack.push(redoStack.top());

		// pop of the top entry in the redo stack
		redoStack.pop();
	}
}
