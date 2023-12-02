#include <string>
#include <sstream>

#pragma once /* чтобы файл при компиляции подключался строго один раз */

class human {
public:
	human(std::string last_name, std::string name, std::string second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	
	virtual std::string get_full_name()
	{
		std::ostringstream full_name;
		full_name << last_name << " "<< name << " "<< second_name;
		return full_name.str();
	}
private:
	std::string name; // Имя
	std::string last_name; // Фамилия
	std::string second_name; // Отчество
};