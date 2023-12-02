#pragma once

#include <map>
#include <string>
#include "person.h"

class Book {
private:
	map<string, Person*> address_book_;
public:
	Book();

	void AddContact(string phone, Person& person);
	void RemoveContact(string phone);
	Person& GetContact(string phone);
	void DisplayContacts(ostream& stream);
	void DisplayContactsDetailed(ostream& stream);
};