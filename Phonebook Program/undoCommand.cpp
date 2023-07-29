/*
 * undoCommand.cpp
 *
 */

#include "undoCommand.h"

using namespace std;

	// constructor
undoCommand::undoCommand(undoRedo &undoRedoObject)
	:urObject(undoRedoObject)
{	}

	// execute function
void undoCommand::execute()
{
	urObject.undo();
}
