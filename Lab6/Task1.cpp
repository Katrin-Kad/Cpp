#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Введите стихотворение (пустая строка - конец ввода)" << endl;
    ofstream fout("lyrics.txt", ios::out);
    if (!fout) {
        cerr << "Не удалось открыть файл";
        return 1;
    }

    string line;
    do {
        getline(cin, line);
        if (line == "") {
            break;
        }

        fout << line.c_str() << endl;
    } while (true);

    fout.close();
    cout << "Стих успешно сохранен в файл";

    return 0;
}
