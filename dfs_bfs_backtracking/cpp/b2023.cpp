#include <iostream>
#include <math.h>
bool is_prime(const int& N) {
	for (int i = 2; i < int(std::sqrt(N)) + 1; ++i) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

void is_special_prime(const int& N, const int& now_N, const int& temp_num) {
	if (now_N == N) {
		std::cout << temp_num << std::endl;
		return;
	}

	for (int i = 1; i < 10; ++i) {
		if (now_N == 0 && i == 1) {
			continue;
		}

		if (is_prime(temp_num * 10 + i)) {
			is_special_prime(N, now_N + 1, temp_num * 10 + i);
		}
	}
	return;
}

int main() {
	int N;
	std::cin >> N;
	is_special_prime(N, 0, 0);
}