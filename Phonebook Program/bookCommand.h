/*
 * bookCommand.h
 *
 */

#ifndef BOOKCOMMAND_H_
#define BOOKCOMMAND_H_

#include <iostream>
#include <string>

#include "command.h"

class bookCommand : public command
{
protected:
	// input and output
	std::istream &in;
	std::ostream &out;

	// functions to show what was displayed and take whatever the user typed and returns
	// it
	void showPrompt(std::string input) const;
	std::string prompt(std::string input);
public:
	// constructor
	bookCommand(std::istream &in, std::ostream &out);
};

#endif /* BOOKCOMMAND_H_ */
