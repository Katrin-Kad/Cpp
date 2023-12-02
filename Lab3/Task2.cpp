#include <iostream>

using namespace std;

float third_pow(int a, int depth);

int main()
{
    int a;
    cout << "Введите число: ";
    cin >> a;

    cout << "Куб. корень (встроенный): " << pow(a, 1.0 / 3) << endl;
    cout << "Куб. корень (итерационная формула): " << third_pow(a, 100) << endl;
}

float third_pow(int a, int depth) {
    if (depth == 0) return a;

    float prev = third_pow(a, depth - 1);

    return (a / (prev * prev) + 2 * prev) / 3;
}
