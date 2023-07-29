/*
 * project3.cpp
 *
 * The main function calls two other functions. testPhoneBook and testList
 *
 * The testList function tests the DoubleLinkedList class.
 *
 * The testPhoneBook function tests the PhoneBook class which also uses
 * the PhoneBookEntry class and the OrderedDoubleLinkedList class.
 *
 */

#include <iostream>
#include <string>

#include "menuList.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"
#include "undoCommand.h"
#include "redoCommand.h"

using namespace std;

int main()
{
	// create phoneBook object
	phoneBook bookList = phoneBook();
	// create undoRedo object
	undoRedo urObject;

	// create the commands
	addUpdateCommand addUpdate(bookList, cin, cout, urObject);
	eraseCommand erase(bookList, cin, cout, urObject);
	printCommand print(bookList, cin, cout);
	undoCommand undo(urObject);
	redoCommand redo(urObject);

	// build the menuList and menuItems
	menuList menu("Phone book menu:");
	// these are the actual menu entries for the application
	menuItem addUpdateItem('a', "add/update", addUpdate);
	menuItem eraseItem('e', "erase", erase);
	menuItem printItem('p', "print", print);
	menuItem undoItem('u', "undo", undo);
	menuItem redoItem('r', "redo", redo);
	// note that the quit command is added to the menu automatically

	// add the menuItem values to the menulist
	menu.add(addUpdateItem);
	menu.add(eraseItem);
	menu.add(printItem);
	menu.add(undoItem);
	menu.add(redoItem);

	std::cout << "Starting the Phone Book" << std::endl;
	std::cout << std::endl;

	// run the menu
	menu.start();

	return 0;
}

