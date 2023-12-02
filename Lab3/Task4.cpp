#include <iostream>

int calculateSum(int n);

using namespace std;

int main()
{
    int n;
    cout << "Введите номер последнего элемента ряда: ";
    cin >> n;
    cout << calculateSum(n);
}

int calculateSum(int n) {
    if (n <= 0) return 0;
    return n * 5 + calculateSum(n - 1);
}
