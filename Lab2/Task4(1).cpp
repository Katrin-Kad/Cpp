#include <iostream>

using namespace std;

int main()
{
    float x, y;

    int max_score = 50;
    int points = 0;

    while (points < max_score) {
        cout << "Enter x и y: ";
        cin >> x >> y;

        float range = sqrt(x * x + y * y);
        if (range <= 1) {
            points += 10;
            cout << "Центр!" << endl;
        }
        else if (range <= 2) {
            points += 5;
            cout << "Второй круг" << endl;
        }
        else {
            cout << "Промах" << endl;
        }

        cout << "Score: " << points << endl;
    }
}