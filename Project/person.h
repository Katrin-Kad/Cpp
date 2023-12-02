#pragma once

#include <string>

using namespace std;


class Person {
protected:
	string first_name_, last_name_;
	string phone_number_;
	int age_;
public:
	Person();
	Person(string first_name, string last_name, string phone_number, int age);

	int GetAge();
	string GetPhoneNumber();
	string GetFirstName();
	string GetLastName();
	string GetFullName();
	string GetShortInfo();

	void SetAge(int age);
	void SetFirstName(string first_name);
	void SetLastName(string last_name);
	void SetPhoneNumber(string phone_number);

	virtual string GetFullInfo() = 0;
	virtual string GetRole() = 0;
};