#include <iostream>
#include "dot.cpp"

using namespace std;

// композиция
//class Triangle {
//private:
//  Dot* dots;
//
//  double* getSidesLengths() {
//    double *sides = new double[3];
//    sides[0] = dots[0].distanceTo(dots[1]);
//    sides[1] = dots[1].distanceTo(dots[2]);
//    sides[2] = dots[2].distanceTo(dots[0]);
//    return sides;
//  }
//
//public:
//  Triangle(double* dotsX, double* dotsY) {
//    dots = new Dot[3];
//    dots[0] = Dot(dotsX[0], dotsY[0]);
//    dots[1] = Dot(dotsX[1], dotsY[1]);
//    dots[2] = Dot(dotsX[2], dotsY[2]);
//  }
//
//  double GetSquare() {
//    auto lengths = getSidesLengths();
//
//    double semi_perimiter = GetPerimeter() / 2;
//    double square = sqrt(semi_perimiter * (semi_perimiter - lengths[0]) * (semi_perimiter - lengths[1]) * (semi_perimiter - lengths[2]));
//
//    return square;
//  }
//
//  double GetPerimeter() {
//    auto lengths = getSidesLengths();
//
//    double perimiter = 0;
//    for (int i = 0; i < 3; i++) {
//      perimiter += lengths[i];
//    }
//
//    return perimiter;
//  }
//
//  void PrintSidesLengths() {
//    auto lengths = getSidesLengths();
//    cout << "Sides lengths: ";
//    for (int i = 0; i < 3; i++) {
//      cout << lengths[i] << " ";
//    }
//    cout << endl;
//  }
//
//  ~Triangle() {
//    delete dots;
//  }
//};

//агрегация
class Triangle {
private:
    Dot *dots;

    double *getSidesLengths() {
        double *sides = new double[3];
        sides[0] = dots[0].distanceTo(dots[1]);
        sides[1] = dots[1].distanceTo(dots[2]);
        sides[2] = dots[2].distanceTo(dots[0]);
        return sides;
    }

public:
    Triangle(Dot *dots) {
        this->dots = dots;
    }

    double GetSquare() {
        auto lengths = getSidesLengths();

        double semi_perimiter = GetPerimeter() / 2;
        double square = sqrt(semi_perimiter * (semi_perimiter - lengths[0]) * (semi_perimiter - lengths[1]) *
                             (semi_perimiter - lengths[2]));

        return square;
    }

    double GetPerimeter() {
        auto lengths = getSidesLengths();

        double perimiter = 0;
        for (int i = 0; i < 3; i++) {
            perimiter += lengths[i];
        }

        return perimiter;
    }

    void PrintSidesLengths() {
        auto lengths = getSidesLengths();
        cout << "Sides lengths: ";
        for (int i = 0; i < 3; i++) {
            cout << lengths[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Введите три точки" << endl;

    double *dotsX = new double[3];
    double *dotsY = new double[3];
    for (int i = 0; i < 3; i++) {
        cout << i << ": ";
        cin >> dotsX[i] >> dotsY[i];
    }

    //В случае с агрегацией
    auto dots = new Dot[3];
    dots[0] = Dot(dotsX[0], dotsY[0]);
    dots[1] = Dot(dotsX[1], dotsY[1]);
    dots[2] = Dot(dotsX[2], dotsY[2]);

    auto triangle = new Triangle(dots);
    //auto triangle = new Triangle(dotsX, dotsY);


    triangle->PrintSidesLengths();
    cout << "Perimiter: " << triangle->GetPerimeter() << endl;
    cout << "Square: " << triangle->GetSquare() << endl;

    delete triangle;
    delete[] dots; //В случае с агрегацией

    return 0;
}
