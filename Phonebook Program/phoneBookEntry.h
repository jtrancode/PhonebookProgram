/*
 * phoneBookEntry.h
 *
 *  Created on: Oct 8, 2018
 *      Author: Jolina Tran
 */

#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <string>

class phoneBookEntry
{
	// variables for name, phone number, and email address
	std::string fullName, pNumber, emailAddress;

public:

	// contructors
	phoneBookEntry();
	phoneBookEntry(const std::string &name, const std::string &number);
	phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email);
	phoneBookEntry(const phoneBookEntry &from);

	// accessor methods
	std::string name() const;
	std::string phoneNumber() const;
	std::string email() const;

	// modifier methods
	void phoneNumber(const std::string &newNumber);
	void email(const std::string &newEmail);
};

#endif /* PHONEBOOKENTRY_H_ */
