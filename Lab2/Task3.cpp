#include <iostream>


int main() {
    int sum;

    std::cout << "Enter sum: ";
    std::cin >> sum;

    int coins[] = {10, 5, 2, 1};

    int len = sizeof(coins) / sizeof(*coins);

    int cnt = 0;

    for (int i = 0; i < len; i++) {
        int taken = sum / coins[i];
        cnt += taken;
        std::cout << coins[i] << " - " << taken << " штук" << std::endl;
        sum -= taken * coins[i];
    }
    std::cout << "Итого: " << cnt << " монет(ы)" << std::endl;
    return 0;
}