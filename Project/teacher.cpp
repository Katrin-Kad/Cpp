#include <set>
#include <vector>
#include "teacher.h"
#include "person.h"

Teacher::Teacher() { }
Teacher::Teacher(string first_name, string last_name, string phone_number, int age, vector<string> objectives) : Person(first_name, last_name, phone_number, age) {
	objectives_ = set<string>{};
	for (string obj : objectives) {
		objectives_.insert(obj);
	}
}

set<string> Teacher::GetObjectives() {
	return objectives_;
}

void Teacher::AddObjective(string objective) {
	objectives_.insert(objective);
}

void Teacher::DeleteObjective(string objective) {
	objectives_.erase(objective);
}

string Teacher::GetFullInfo() {
	stringstream info;
	info << "Teacher: " << GetFullName() << endl;
	info << "Age: " << GetAge() << endl;
	info << "Lessons: ";
	for (string obj : objectives_) {
		info << obj << ",";
	}

	return info.str();
}

string Teacher::GetRole() {
	return Role;
}