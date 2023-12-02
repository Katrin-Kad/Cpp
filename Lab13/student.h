#pragma once

#include "human.h"
#include <string>
#include <vector>

class student : public human {
public:
	student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores);

	float get_average_score();


	std::string get_full_name() override;
private:
	std::vector<int> scores;
};