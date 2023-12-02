#include <iostream>
#include <map>
#include <string>

using namespace std;

class StudentGrade {
public:
    string name;
    char grade;

    StudentGrade() { }
    StudentGrade(string name, char grade) {
        this->name = name;
        this->grade = grade;
    }
};

int main()
{
    StudentGrade first ("Первый",'A');
    StudentGrade second ("Второй",'B');
    StudentGrade third ("Третий",'C');

    map<string, StudentGrade> grades;
    grades[first.name] = first;
    grades[second.name] = second;
    grades[third.name] = third;

    for (const auto& x: grades)
    {
        cout << "Ученик: " << x.first << " - Оценка: " << x.second.grade << endl;
    }

    grades["Первый"].grade = 'D';
    grades["Второй"].grade = 'E';
    grades["Третий"].grade = 'F';

    cout << "После изменений" << endl;
    for (const auto& x : grades)
    {
        cout << "Ученик: " << x.first << " - Оценка: " << x.second.grade << endl;
    }
}
