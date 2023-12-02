#include <string>
#include "person.h"

using namespace std;

Person::Person() { }
Person::Person(string first_name, string last_name, string phone_number, int age) {
	first_name_ = first_name;
	last_name_ = last_name;
	phone_number_ = phone_number;
	age_ = age;
}

int Person::GetAge() {
	return age_;
}

string Person::GetPhoneNumber() {
	return phone_number_;
}

string Person::GetFullName() {
	return first_name_ + " " + last_name_;
}

string Person::GetFirstName() {
	return first_name_;
}

string Person::GetLastName() {
	return last_name_;
}

void Person::SetAge(int age) {
	age_ = age;
}

void Person::SetFirstName(string first_name) {
	first_name_ = first_name;
}

void Person::SetLastName(string last_name) {
	last_name_ = last_name;
}

void Person::SetPhoneNumber(string phone_number) {
	phone_number_ = phone_number;
}

string Person::GetShortInfo() {
	return GetRole() + ": " + GetFullName();
}