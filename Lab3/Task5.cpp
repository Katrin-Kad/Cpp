//
// Created by Sergei Kononchuk on 30.09.2023.
//

#include <iostream>
#include <string>

using namespace std;

string parseToBinary(int num);

int main()
{
    int x;
    cout << "Введите число: ";
    cin >> x;
    cout << parseToBinary(x);
}

string parseToBinary(int num) {
    if (num <= 0) return "";

    int remainder = num % 2;
    num /= 2;

    return parseToBinary(num) + to_string(remainder);
}