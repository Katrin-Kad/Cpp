#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "book.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "person_reader.h"
#include "book.cpp"
#include "person.cpp"
#include "person_reader.cpp"
#include "student.cpp"
#include "teacher.cpp"


using namespace std;

int main() {
    Book book{};
    PersonReader reader{};

    Person *person = reader.ReadPerson(&cin, &cout);
    while (person != NULL) {
        book.AddContact(person->GetPhoneNumber(), *person);
        person = reader.ReadPerson(&cin, &cout);
    }

    ofstream fstream("C++/Project/adress_book.txt", ios::out);

    book.DisplayContacts(fstream);
    fstream << endl << endl;
    book.DisplayContactsDetailed(fstream);

    fstream.close();
}