/*
 * phoneBook.cpp
 *
 */

#include <iomanip>

#include "phoneBook.h"

using namespace std;

	// constructor
phoneBook::phoneBook() {}

	// insert functions
void phoneBook::insert(const phoneBookEntry &entry)
{
	// check if entry with same name
	if(find(entry.name()))
	{
		// if so, find its position and update it with new entry
		for(int i = 0; i < phoneBookList.size(); i++)
		{
			if(phoneBookList[i].name() == entry.name())
				phoneBookList[i] = entry;
		}
	}
	else
		// otherwise add the entry at the end
		phoneBookList.push_back(entry);
}
void phoneBook::insert(const string &name, const string &number)
{
	// call original insert to check
	insert(phoneBookEntry(name, number));
}
void phoneBook::insert(const string &name, const string &number, const string &email)
{
	// call original insert to check
	insert(phoneBookEntry(name, number, email));
}

	// erase an entry with the same name
bool phoneBook::erase(string name)
{
	// go through the vector
	for(int i = 0; i < phoneBookList.size(); i++)
	{
		// if the entry's name in the current position in the vector matches the string,
		// delete that entry from the vector
		if(phoneBookList[i].name() == name)
		{
			phoneBookList.erase(phoneBookList.begin() + i);
			return true;
		}
	}

	// if nothing gets deleted, return false
	return false;
}
	//check if a entry is in the vector using a name
bool phoneBook::find(string name)
{
	// go through the vector
	for(int i = 0; i < phoneBookList.size(); i++)
	{
		// check if the current entry's name in the vector matches the string. if it
		// does, return true
		if(phoneBookList[i].name() == name)
			return true;
	}

	// if it's not found, return false
	return false;
}

	// get the size of the vector
size_t phoneBook::size() const
{
	return phoneBookList.size();
}

	// iterators for the beginning and end of the vector
phoneBook::iterator phoneBook::begin()
{
	return phoneBookList.begin();
}
phoneBook::iterator phoneBook::end()
{
	return phoneBookList.end();
}

// print functions
void phoneBook::print() const
{
	print(cout);
}
void phoneBook::print(ostream &out) const
{
	// make it fixed and left aligned then set the width of the "Name:" column to 31,
	// "Phone Number:" column to 16 and print for first line
	out << fixed << left;
	out << setw(31) << "Name:";
	out	<< setw(16) << "Phone Number:";
	out << "E-Mail:" << endl;

	// go through list and print out each name, phone number, and email accordingly
	for(phoneBookEntry entry : phoneBookList)
	{
		out << setw(31) << entry.name();
		out << setw(16) << entry.phoneNumber();
		out << entry.email() << endl;
	}
}

	// for debugging
void phoneBook::debug(ostream &out) const { }
