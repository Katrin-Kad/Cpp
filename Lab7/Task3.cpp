//
// Created by Sergei Kononchuk on 29.10.2023.
//
#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

tuple<bool, double, double> MyRoot(double a, double b, double c) {
    double d = b * b - 4 * a * c;

    tuple<bool, double, double> result;
    if (d >= 0) {
        double sqrtD = sqrt(d);
        double x1 = (-b - sqrtD) / (2 * a);
        double x2 = (-b + sqrtD) / (2 * a);

        result = make_tuple(true, x1, x2);
    }
    else {
        result = make_tuple(false, 0, 0);
    }

    return result;
}

int main()
{
    double a, b, c;
    cout << "Введите a, b и c: ";
    cin >> a >> b >> c;

    auto result = MyRoot(a, b, c);
    if (!get<0>(result))
        cout << "Корней нет";
    else if (get<1>(result) == get<2>(result))
        cout << "Корень один: " << get<1>(result);
    else
        cout << "Корня два: " << get<1>(result) << " и " << get<2>(result);
}