#pragma once

#include <string>
#include "person.h"

using namespace std;

class Student : public Person {
private:
	const int MaxCourse = 4;
	const string Role = "Student";

	bool in_university_;
	int course_number_;

public:
	Student();
	Student(string first_name, string last_name, string phone_number, int age, int course_number);

	int GetCourse();

	void EndCourse();

	bool IsInUniversity();
	void LeaveUniversity();
	void EnterUniversity(int course);

	string GetFullInfo() override;
	string GetRole() override;
};