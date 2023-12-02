//
// Created by Sergei Kononchuk on 02.11.2023.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename TContainer>
void Print(const TContainer &arr, string delimiter) {
    bool isFirstIter = true;
    for (const auto &obj: arr) {
        if (!isFirstIter) {
            cout << delimiter;
        } else {
            isFirstIter = false;
        }

        cout << obj;
    }

    cout << endl;
}

int main() {
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);
    Print(data, ", ");
}