//
// Created by Sergei Kononchuk on 30.09.2023.
//
#include <iostream>

using namespace std;

int* max_vect(int length, int a[], int b[]);

int main()
{
    int a[] = { 1,2,3,4,5,6,7,2 };
    int b[] = { 7,6,5,4,3,2,1,3 };
    int kc = sizeof(a) / sizeof(a[0]); //Количество элементов массива
    int* c; //Указатель на результирующий массив
    c = max_vect(kc, a, b); //вызов функции для создания массива
    for (int i = 0;i < kc; i++) //Вывод результата.
        cout << c[i] << " ";
    cout << endl;
    delete[]c; //Возврат памяти.
}

int* max_vect(int length, int a[], int b[]) {
    int* result = new int[length];

    for (int i = 0; i < length; i++) {
        result[i] = max(a[i], b[i]);
    }

    return result;
}