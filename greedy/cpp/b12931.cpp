#include <iostream>

int N;
int nums[50];

bool check() {
	for (int i = 0; i < N; ++i) {
		if (nums[i] > 1) {
			return true;
		}
	}
	return false;
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> nums[i];
	}

	int cnt = 0;
	while (check()) {
		for (int i = 0; i < N; ++i) {
			if (nums[i] > 1) {
				cnt += nums[i] % 2;
				nums[i] = nums[i] / 2;
			}
		}
		cnt += 1;
	}

	for (int i = 0; i < N; ++i) {
		if (nums[i]) {
			cnt += 1;
		}
	}
	std::cout << cnt << std::endl;
}