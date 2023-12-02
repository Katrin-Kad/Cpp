#include <iostream>
#include <string>

using namespace std;

bool isSnils(string str) {
    if (str.length() != 11) {
        return false;
    }

    int sum = 0;

    int prev_number = -1;
    int double_prev_number = -1;
    for (int i = 0; i < 9; i++) {
        int number = str[i] - '0';
        if (number == prev_number && number == double_prev_number) {
            return false;
        }

        sum += number * (9 - i);

        double_prev_number = prev_number;
        prev_number = number;
    }

    int control_sum = (str[9] - '0') * 10 + (str[10] - '0');
    if (sum < 100) {
        return control_sum == sum;
    }
    if (sum == 100 || sum == 101) {
        return control_sum == 0;
    }
    if (sum > 101) {
        int remainder = sum % 101;
        if (remainder < 100) {
            return remainder == sum;
        }
        if (remainder == 100) {
            return sum == 0;
        }
    }

}

string ParseRawSnils(string str) {

    string snils = "";
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            snils += str[i];
        }
        else if (str[i] == ' ' || str[i] == '-') {
            continue;
        }
        else {
            return "";
        }
    }

    return snils;
}

int main()
{
    string input;
    cout << "Введите СНИЛС: ";
    getline(cin, input);

    string snils = ParseRawSnils(input);
    if (isSnils(snils))
        cout << "True";
    else
        cout << "False";
}
