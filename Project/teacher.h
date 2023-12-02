#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "person.h"

class Teacher : public Person {
private:
	string const Role = "Teacher";

	set<string> objectives_;
public:
	Teacher();
	Teacher(string first_name, string last_name, string phone_number, int age, vector<string> objectives);

	set<string> GetObjectives();
	void AddObjective(string objective);
	void DeleteObjective(string objective);

	string GetFullInfo() override;
	string GetRole() override;
};
