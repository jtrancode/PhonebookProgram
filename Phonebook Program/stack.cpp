/*
 * stack.cpp
 *
 */

#include "stack.h"

using namespace std;

/* stackEntry implementation */
	// constructor
stackEntry::stackEntry(command *theCommand, stackEntry *pNext)
{
	pCommand = theCommand;
	pNextEntry = pNext;
}

	// destructor
stackEntry::~stackEntry() {}

	// function to go to next entry in stack
void stackEntry::next(stackEntry *pNext)
{
	pNextEntry = pNext;
}

	// accessor methhods
command* stackEntry::data()
{
	return pCommand;
}
const command* stackEntry::data() const
{
	return pCommand;
}

	// returns the stackEntry that is next
stackEntry* stackEntry::next()
{
	return pNextEntry;
}


/* stack implementation */
	// constructors
stack::stack()
{
	pTopEntry = nullptr;
	stackSize = 0;
}
	// destructor
stack::~stack()
{
	// while the stack still have entries in them, pop entries off the stack
	while(!empty())
		pop();
}

	// accessor methods
command* stack::top()
{
	if(pTopEntry)
		return pTopEntry->data();
	else
		return nullptr;
}
const command* stack::top() const
{
	if(pTopEntry)
		return pTopEntry->data();
	else
		return nullptr;
}

	// check if stack is empty
bool stack::empty() const
{
	return (size() == 0);
}

	// return size of stack
size_t stack::size() const
{
	return stackSize;
}

	// put a new stackEntry on top of the stack
void stack::push(command *newCommand)
{
	// create new stackEntry and set it to the top entry
	pTopEntry = new stackEntry(newCommand, pTopEntry);
	// add 1 to size of stack
	stackSize++;
}

	// pop off the top entry of the stack
void stack::pop()
{
	// check if stack is empty
	if(!empty())
	{
		// stackEntry to hold stuff to move
		stackEntry *hold = pTopEntry;

		// set top entry to the next entry
		pTopEntry = pTopEntry->next();

		// "pop" off what was the top entry (hold) aka delete it
		delete hold;

		// decrease size of stack by 1
		stackSize--;
	}
}

	// debugging
void stack::debug() const {}
void stack::debug(std::ostream &out) const {}
