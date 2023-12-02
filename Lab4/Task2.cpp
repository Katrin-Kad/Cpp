#include <iostream>

using namespace std;

bool Input(int& a, int& b);

int main()
{
    int a, b;
    if (!Input(a, b))
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    return 0;
}

bool Input(int& a, int& b) {
    cin >> a >> b;
    if (!cin) {
        return false;
    }

    return true;
}
