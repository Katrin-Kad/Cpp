//
// Created by Sergei Kononchuk on 30.09.2023.
//
#include <iostream>

using namespace std;

float square(int a);
float square(int a, int b, int c);

int main()
{
    int type;
    cout << "Выберите тип треугольника, 1 - равносторонний, 2 - разносторонний: ";
    cin >> type;

    float triangle_square;
    if (type == 1) {
        int a;
        cout << "Введите сторону: ";
        cin >> a;

        triangle_square = square(a);
    }
    else {
        int a, b, c;
        cout << "Введите три стороны: ";
        cin >> a >> b >> c;

        triangle_square = square(a, b, c);
    }

    cout << "Площадь = " << triangle_square;
}

float square(int a) {
    float half_perimiter = (float)(a * 3) / 2;
    float square = sqrt(half_perimiter * pow(half_perimiter - a, 3));

    return square;
}

float square(int a, int b, int c) {
    float semi_perimiter = (float)(a + b + c) / 2;
    float square = sqrt(semi_perimiter * (semi_perimiter - a) * (semi_perimiter - b) * (semi_perimiter - c));

    return square;
}