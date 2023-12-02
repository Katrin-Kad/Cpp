#include <iostream>

bool isPrime(int x) {
    if (x == 1)
        return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}


bool IsSuperPrime(int x) {
    if (!isPrime(x))
        return false;

    int pos = 0;
    for (int i = 2; i <= x; i++) {
        if (isPrime(i)) {
            pos++;
        }
    }

    return isPrime(pos);
}


int main() {
    int x;
    std::cout << "Enter x: ";
    std::cin >> x;

    if (IsSuperPrime(x))
        std::cout << "Super prime";
    else
        std::cout << "Not Super Prime";

    return 0;
}