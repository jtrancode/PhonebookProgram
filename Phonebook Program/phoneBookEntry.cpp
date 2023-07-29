/*
 * phoneBookEntry.cpp
 *
 */
#include <string>

#include "phoneBookEntry.h"

using namespace std;

	// contructors
phoneBookEntry::phoneBookEntry()
	:fullName(""), pNumber(""), emailAddress("")
{	}
phoneBookEntry::phoneBookEntry(const string &name, const string &number)
	:fullName(name), pNumber(number)
{	}
phoneBookEntry::phoneBookEntry(const string &name, const string &number,  const string &email)
	:fullName(name), pNumber(number), emailAddress(email)
{	}
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from)
	:fullName(from.name()), pNumber(from.phoneNumber()), emailAddress(from.email())
{	}

	// accessor methods
string phoneBookEntry::name() const
{
	return fullName;
}
string phoneBookEntry::phoneNumber() const
{
	return pNumber;
}
string phoneBookEntry::email() const
{
	return emailAddress;
}

	// modifier methods
void phoneBookEntry::phoneNumber(const string &newNumber)
{
	pNumber = newNumber;
}
void phoneBookEntry::email(const string &newEmail)
{
	emailAddress = newEmail;
}
