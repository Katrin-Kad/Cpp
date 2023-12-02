//
// Created by Sergei Kononchuk on 30.09.2023.
//

#include <iostream>

using namespace std;

int IndexOf(int arr[], int len, int key);
void PrintArray(int arr[], int length);

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,2 };
    int len = sizeof(arr) / sizeof(arr[0]);

    int index = IndexOf(arr, len, 7);
    cout << "Index = " << index << endl;
    PrintArray(arr, len);

    index = IndexOf(arr, len, 7);
    cout << "Index = " << index << endl;
    PrintArray(arr, len);

    index = IndexOf(arr, len, 2);
    cout << "Index = " << index << endl;
    PrintArray(arr, len);
}

int IndexOf(int arr[], int len, int key) {
    if (arr[0] == key) return 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] == key) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;

            return i - 1;
        }
    }

    return -1;
}

void PrintArray(int arr[], int length) {
    cout << "{ ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}