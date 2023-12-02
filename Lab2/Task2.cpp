#include <iostream>
#include <string>


bool isSnils(std::string str) {
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

int main() {
    std::string snils;
    std::cout << "Enter СНИЛС: ";

    std::cin >> snils;

    if (isSnils(snils))
        std::cout << "True";
    else
        std::cout << "False";
}