#include "human.h"
#include "student.h"
#include <string>
#include <vector>

student::student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores) 
	: human(last_name, name,second_name) 
{
	this->scores = scores;
}
	
float student::get_average_score()
{
	unsigned int count_scores = scores.size();
	unsigned int sum_scores = 0;

	float average_score;
	for (unsigned int i = 0; i < count_scores; ++i) {
		sum_scores += this->scores[i];
	}
	average_score = (float)sum_scores / (float)count_scores;
	return average_score;
}

std::string student::get_full_name() {
	return "Студент: " + human::get_full_name();
}