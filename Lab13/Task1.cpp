#include <iostream>
#include <vector>
#include "human.h"
#include "teacher.h"
#include "student.cpp"

int main()
{
	// Оценки студента
	std::vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	student* stud = new student("Петров", "Иван", "Алексеевич", scores);
	std::cout << ((human*)(stud))->get_full_name() << std::endl;

	std::cout << "Средний балл : " << stud->get_average_score() << std::endl;

	unsigned int teacher_work_time = 40;
	teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

	std::cout << ((human*)(tch))->get_full_name() << std::endl;
	std::cout << "Количество часов: " << tch->get_work_time() << std::endl;
	return 0;
}