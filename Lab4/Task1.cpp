#include <iostream>

using namespace std;

int MyRoot(double, double, double, double&, double&);

int main()
{
    double a, b, c;
    cout << "Введите a, b и c: ";
    cin >> a >> b >> c;

    double x1, x2;
    int result = MyRoot(a, b, c, x1, x2);
    if (result == -1)
        cout << "Корней нет";
    else if (result == 0)
        cout << "Корень один: " << x1;
    else
        cout << "Корня два: " << x1 << " и " << x2;
}

int MyRoot(double a, double b, double c, double& x1, double& x2) {
    double d = b * b - 4 * a * c;

    if (d < 0) return -1;

    double sqrtD = sqrt(d);
    x1 = (-b - sqrtD) / (2 * a);
    x2 = (-b + sqrtD) / (2 * a);

    if (d == 0) return 0;

    return 1;
}
