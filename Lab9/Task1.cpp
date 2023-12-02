#include <iostream>
#include <string>

using namespace std;

class NonValidTriangleException {
public:
    string message;
    NonValidTriangleException(string message) {
        this->message = message;
    }
};

class Triangle {
private:
    int a, b, c;
public:
    Triangle(int a, int b, int c) {
        if (a + b <= c || b + c <= a || a + c <= b) {
            throw NonValidTriangleException("Треугольник с такими сторонами не существует");
        }

        this->a = a;
        this->b = b;
        this->c = c;
    }

    float Square() {
        float semi_perimiter = (float)(a + b + c) / 2;
        float square = sqrt(semi_perimiter * (semi_perimiter - a) * (semi_perimiter - b) * (semi_perimiter - c));

        return square;
    }
};

int main()
{
    int a, b, c;
    cout << "Введите три стороны: ";
    cin >> a >> b >> c;

    Triangle* triangle;
    try {
        triangle = new Triangle(a, b, c);
    }
    catch(NonValidTriangleException ex){
        cerr << ex.message;
        return 1;
    }

    cout << "Площадь = " << triangle->Square();
}
