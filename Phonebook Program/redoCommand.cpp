/*
 * redoCommand.cpp
 *
 */

#include "redoCommand.h"

using namespace std;

	// constructor
redoCommand::redoCommand(undoRedo &undoRedoObject)
	:urObject(undoRedoObject)
{	}

	// execute function
void redoCommand::execute()
{
	urObject.redo();
}


