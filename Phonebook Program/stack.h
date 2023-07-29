/*
 * stack.h
 *
 *  The stack class is a stack data structor for command pointers. The entries that make up the start are of
 *  type stackEntry.
 *
 *  Created on: Oct 1, 2018
 *      Author: dgv130030
 */

#ifndef STACK_H_
#define STACK_H_

#include <cstddef>
#include <iostream>
#include <iomanip>

#include "command.h"

class command;

class stackEntry
{
public:
	// stack is a friend class of stackEntry
	friend class stack;
private:
	// pointers for command object and next entry
	command *pCommand;
	stackEntry *pNextEntry;
protected:
	// constructor
	stackEntry(command *theCommand, stackEntry *pNext = nullptr);

	// destructor
	virtual ~stackEntry();

	// function to go to next entry in stack
	virtual void next(stackEntry *pNext);

	// acessor methods
	virtual command* data();
	virtual const command* data() const;

	// returns the stackEntry that is next
	virtual stackEntry* next();
};

class stack
{
	// pointer for the stackEntry at the top
	stackEntry *pTopEntry;
	// size of stack
	std::size_t stackSize;
public:
	// constructors
	stack();
	stack(const stack &from) = delete;
	stack& operator=(const stack &from) = delete;

	// destructor
	virtual ~stack();

	// accessor methods
	command* top();
	const command* top() const;

	// check if stack is empty
	bool empty() const;

	// return size of stack
	std::size_t size() const;

	// put a new stackEntry on top of the stack
	void push(command *newCommand);

	// pop off the top entry of the stack
	void pop();

	// debugging
	void debug() const;
	void debug(std::ostream &out) const;
};

#endif /* STACK_H_ */
