/*
 * printCommand.h
 *
 *  Created on: Oct 8, 2018
 *      Author: Jolina Tran
 */

#ifndef PRINTCOMMAND_H_
#define PRINTCOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

class printCommand : public bookCommand
{
	phoneBook &book;
public:
	// constructor
	printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);

	// execute function
	virtual void execute();
};

#endif /* PRINTCOMMAND_H_ */
