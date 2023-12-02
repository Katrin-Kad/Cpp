#include <iostream>

template<typename T, size_t N>
double avg(const T (&arr)[N]) {
    double divisor = (double) N;
    double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i] /
               divisor; //Такой вид нахождения для предотвращения переполнения границ типа при суммировании (например с char)
    }

    return sum;
}

int main() {
    int arr[] = {4, 4, 4, 4, 4};
    std::cout << avg(arr) << std::endl;

    long arrl[] = {4l, 4l, 4l, 4l, 4l};
    std::cout << avg(arrl) << std::endl;

    double arrd[] = {4.5, 4.5, 4.5, 4.5, 4.5};
    std::cout << avg(arrd) << std::endl;

    char arrc[] = {'A', 'A', 'A', 'A', 'A'}; // 'A' - код = 65
    std::cout << avg(arrc) << std::endl;
}
