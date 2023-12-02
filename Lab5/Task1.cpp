//
// Created by Sergei Kononchuk on 30.09.2023.
//

#include <iostream>

using namespace std;

void InputArray(int arr[], int length);
int Sum(int arr[], int length);
float Avg(int arr[], int length);
int SumOfNegative(int arr[], int length);
int SumOfPositive(int arr[], int length);
int SumOfOddIndexes(int arr[], int length);
int SumOfEvenIndexes(int arr[], int length);
int IndexOfMin(int arr[], int length);
int IndexOfMax(int arr[], int length);
void BubbleSort(int arr[], int length);
void PrintArray(int arr[], int length);

int main()
{
    const int n = 10;

    int arr[n];
    InputArray(arr, n);

    int sum = Sum(arr, n);
    cout << "Sum: " << sum << endl;

    float avg = Avg(arr, n);
    cout << "Avg: " << avg << endl;

    int sumOfNegative = SumOfNegative(arr, n);
    cout << "Sum Of Negative: " << sumOfNegative << endl;

    int sumOfPositive = SumOfPositive(arr, n);
    cout << "Sum Of Positive: " << sumOfPositive << endl;

    int sumOfOddIndexes = SumOfOddIndexes(arr, n);
    cout << "Sum Of Odd Indexes: " << sumOfOddIndexes << endl;

    int sumOfEvenIndexes = SumOfEvenIndexes(arr, n);
    cout << "Sum Of Even Indexes: " << sumOfEvenIndexes << endl;

    int indexOfMin = IndexOfMin(arr, n);
    cout << "Index Of Min: " << indexOfMin << endl;

    int indexOfMax = IndexOfMax(arr, n);
    cout << "Index Of Max: " << indexOfMax << endl;

    BubbleSort(arr, n);
    PrintArray(arr, n);
}

void InputArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
}

int Sum(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }

    return sum;
}

float Avg(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }

    return (float)sum / length;
}

int SumOfNegative(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if(arr[i] < 0)
            sum += arr[i];
    }

    return sum;
}

int SumOfPositive(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > 0)
            sum += arr[i];
    }

    return sum;
}

int SumOfOddIndexes(int arr[], int length) {
    int sum = 0;
    for (int i = 1; i < length; i += 2) {
        sum += arr[i];
    }

    return sum;
}

int SumOfEvenIndexes(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i += 2) {
        sum += arr[i];
    }

    return sum;
}

int IndexOfMin(int arr[], int length) {
    int min = INT32_MAX;
    int minIndex = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int IndexOfMax(int arr[], int length) {
    int max = INT32_MIN;
    int maxIndex = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
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

void PrintArray(int arr[], int length) {
    cout << "{ ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}