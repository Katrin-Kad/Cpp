#pragma once

#include <iostream>
#include "person.h"

class PersonReader {
private:
	
public:
	PersonReader();

	Person* ReadPerson(istream* inp_stream_, ostream* ask_stream_ = 0);
};