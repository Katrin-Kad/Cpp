//
// Created by Sergei Kononchuk on 29.10.2023.
//

#include <iostream>

using namespace std;

struct QuadraticEquation {
    bool SolutionExist;
    float X1, X2;
};

QuadraticEquation MyRoot(double a, double b, double c) {
    double d = b * b - 4 * a * c;

    QuadraticEquation equation;
    if (d >= 0) {
        equation.SolutionExist = true;

        double sqrtD = sqrt(d);
        equation.X1 = (-b - sqrtD) / (2 * a);
        equation.X2 = (-b + sqrtD) / (2 * a);
    }
    else {
        equation.SolutionExist = false;
    }

    return equation;
}

int main()
{
    double a, b, c;
    cout << "Введите a, b и c: ";
    cin >> a >> b >> c;

    QuadraticEquation result = MyRoot(a, b, c);
    if (!result.SolutionExist)
        cout << "Корней нет";
    else if (result.X1 == result.X2)
        cout << "Корень один: " << result.X1;
    else
        cout << "Корня два: " << result.X1 << " и " << result.X2;
}