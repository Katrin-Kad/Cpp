#include <iostream>
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "person_reader.h"

PersonReader::PersonReader() {

}

Person* PersonReader::ReadPerson(istream* inp_stream_, ostream* ask_stream_) {
	if (ask_stream_ != NULL) {
		*ask_stream_ << "Select person type: s-student, t-teacher, q-exit" << endl;
	}

	char type;
	*inp_stream_ >> type;

	if (type == 's') {
		string first_name, last_name, phone_number;
		int age, course;

		if (ask_stream_ != NULL)
			*ask_stream_ << "Insert name, surname, phone number, age and course:" << endl;
		*inp_stream_ >> first_name >> last_name >> phone_number;
		*inp_stream_ >> age >> course;

		return new Student(first_name, last_name, phone_number, age, course);
	}
	else if (type == 't') {
		string first_name, last_name, phone_number;
		int age;
		vector<string> objectives{};

		if (ask_stream_ != NULL)
			*ask_stream_ << "Insert name, surname, phone number, age:" << endl;
		*inp_stream_ >> first_name >> last_name >> phone_number;
		*inp_stream_ >> age;

		if (ask_stream_ != NULL)
			*ask_stream_ << "Insert teacher's courses, and write q:" << endl;

		string objective;
		while (*inp_stream_ >> objective && objective != "q") {
			objectives.push_back(objective);
		}

		return new Teacher(first_name, last_name, phone_number, age, objectives);
	}
	else {
		return NULL;
	}
}
