//
// Created by Sergei Kononchuk on 30.09.2023.
//

#include <iostream>
#include <fstream>

using namespace std;

void InputArray(int arr[], int length);
void BubbleSort(int arr[], int length);
void PrintArray(ostream& dest, int arr[], int length);

int main()
{
    const int n = 10;

    int arr[n];
    InputArray(arr, n);

    ofstream fout("array.txt", ios::out);
    if (!fout) {
        cerr << "Не удалось открыть файл";
        return 1;
    }

    PrintArray(fout, arr, n);
    BubbleSort(arr, n);
    PrintArray(fout, arr, n);

    fout.close();
}

void InputArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
}

void BubbleSort(int arr[], int length) {
    int min = 0;
    int buf = 0;
    for (int i = 0; i < length; i++)
    {
        min = i;
        for (int j = i + 1; j < length; j++)
            min = (arr[j] < arr[min]) ? j : min;

        if (i != min)
        {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
}

void PrintArray(ostream& dest, int arr[], int length) {
    dest << "{ ";
    for (int i = 0; i < length; i++) {
        dest << arr[i] << " ";
    }
    dest << "}" << endl;
}