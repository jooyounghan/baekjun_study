#include <iostream>

int main() {
    long long nums;
    std::cin >> nums;
    long long num = 0;
    long long temp = nums;
    for (long long  i = 1; i < nums + 1; i++) {
        temp -= i;
        if (temp >= 0) {
            num += 1;
            continue;
        }
        else { break; }
    }
    std::cout << num << std::endl;
}
