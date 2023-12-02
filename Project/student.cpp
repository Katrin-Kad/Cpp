#include <string>
#include <sstream>
#include "person.h"
#include "student.h"

using namespace std;

Student::Student() { }
Student::Student(string first_name, string last_name, string phone_number, int age, int course_number) : Person(first_name, last_name, phone_number, age) {
	in_university_ = true;
	course_number_ = course_number;
}

int Student::GetCourse() {
	if(in_university_)
		return course_number_;
	return -1;
}

void Student::EndCourse() {
	if (course_number_ == -1) return;

	course_number_++;
	if (course_number_ > Student::MaxCourse) {
		course_number_ = -1;
		in_university_ = false;
	}
}

bool Student::IsInUniversity() {
	return in_university_;
}

void Student::LeaveUniversity() {
	course_number_ = -1;
	in_university_ = false;
}

void Student::EnterUniversity(int course) {
	course_number_ = course;
	in_university_ = true;
}

string Student::GetFullInfo() {
	stringstream info;
	info << "Student: " << GetFullName() << endl;
	info << "Age: " << GetAge() << endl;
	if (in_university_) {
		info << "University: " << course_number_ << " course" << endl;
	}
	else {
		info << "No studying in university";
	}
	
	return info.str();
}

string Student::GetRole() {
	return Student::Role;
}
