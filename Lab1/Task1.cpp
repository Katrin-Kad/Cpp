#include <iostream>
#include <cmath>

int main()
{
    int x[5];
    int y[5];

    std::cout << "Insert coords (format 'x y'): " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> x[i];
        std::cin >> y[i];
    }

    int area = x[4] * y[0] - x[0] * y[4];
    for (int i = 0; i < 4; i++) {
        area += x[i] * y[i + 1];
        area -= x[i + 1] * y[i];
    }

    std::cout << "Area: " << fabs(area) / 2;

    /*
    * Пример пятиугольника
    * 3 4
    * 5 11
    * 12 8
    * 9 5
    * 5 6
    * = 30
    */
}