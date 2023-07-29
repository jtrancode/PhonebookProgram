/*
 * phoneBook.h
 *
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include <iostream>
#include <string>
#include <vector>

#include "phoneBookEntry.h"

class phoneBook
{
public:
	// constructor
	phoneBook();

	// insert functions
	void insert(const phoneBookEntry &entry);
	void insert(const std::string &name, const std::string &number, const std::string &email);
	void insert(const std::string &name, const std::string &number);

	// erase function to delete entry
	bool erase(std::string name);
	// find function to find an entry
	bool find(std::string name);

	// return size of the list of entries
	std::size_t size() const;

	// type definition for vector and interators
	typedef std::vector<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;
	iterator begin();
	iterator end();

	// print contents of phoneBook
	void print() const;
	void print(std::ostream &out) const;

	// function for debugging
	void debug(std::ostream &out) const;
private:
	// vector
	phoneBook::phoneBookEntryList phoneBookList;
};

#endif /* PHONEBOOK_H_ */
