#include <string>
#include <sstream>
#include <iostream>
#include "book.h"
#include "person.h"

Book::Book() {
	address_book_ = map<string, Person*>{};
}

void Book::AddContact(string phone, Person& person) {
	address_book_[phone] = &person;
}

void Book::RemoveContact(string phone) {
	address_book_.erase(phone);
}


Person& Book::GetContact(string phone) {
	return *address_book_[phone];
}

void Book::DisplayContacts(ostream& stream) {
	stream << "Contacts count: " << address_book_.size() << endl;
	for (auto& contact : address_book_) {
		stream << contact.second->GetShortInfo() << endl;
	}
}

void Book::DisplayContactsDetailed(ostream& stream) {
	stream << "Contacts count: " << address_book_.size() << endl;
	for (auto& contact : address_book_) {
		stream << contact.second->GetFullInfo() << endl;
	}
}