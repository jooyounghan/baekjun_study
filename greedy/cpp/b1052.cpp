#include <iostream>

int N, K;

int check_bottles(int nums) {
	int cnt = 0;
	while (nums) {
		if (nums % 2) {
			cnt++;
		}
		nums = nums / 2;
	}
	return cnt;
}

int main() {
	std::cin >> N >> K;
	int result = 0;
	int cnt = 1;
	while (check_bottles(N) > K) {
		if (N & 1) {
			N += 1;
			result += cnt;
		}
		N = N >> 1;
		cnt *= 2;
	}
	std::cout << result << std::endl;
}