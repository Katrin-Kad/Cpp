#include <iostream>

using namespace std;

bool TryParseInt(const char* str, int& result);

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        cerr << "Ошибка - Кол-во параметров меньше 4";
        return 1;
    }

    string operation = string(argv[1]);
    if (operation != "-a" && operation != "-m") {
        cerr << "Ошибка - Второй параметр должен быть -a или -m. Получено:" << operation;
        return 1;
    }

    int first, second;
    if (!TryParseInt(argv[2], first)) {
        cerr << "Ошибка - Третий параметр не число. Получено:" << argv[2];
        return 1;
    }

    if (!TryParseInt(argv[3], second)) {
        cerr << "Ошибка - Четвертый параметр не число. Получено:" << argv[3];
        return 1;
    }

    if (operation == "-a") {
        cout << first << " + " << second << " = " << (first + second);
    }
    else {
        cout << first << " * " << second << " = " << (first * second);
    }

    return 0;
}

bool TryParseInt(const char* str, int& result) {
    result = atoi(str);
    if (result == 0 && string(str) != "0") { //atoi возвращает 0 при некорректном вводе, проверка на то что пользователь сам ввел 0
        return false;
    }

    return true;
}
