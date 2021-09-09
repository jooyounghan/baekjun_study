#include <iostream>

int beads[10];
bool used[10];

int N;
int max_num = 0;

void backtracking(const int& temp_max, const int& cnt) {
	if (cnt == N - 2) {
		if (max_num < temp_max) {
			max_num = temp_max;
		}
		return;
	}

	for (int i = 1; i < N - 1; ++i) {
		if (!used[i]) {
			used[i] = true;
			int left_idx = i - 1;
			int right_idx = i + 1;
			while (used[left_idx]) {
				left_idx--;
			}
			while (used[right_idx]) {
				right_idx++;
			}
			backtracking(temp_max + beads[left_idx] * beads[right_idx], cnt + 1);
			used[i] = false;
		}
	}
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> beads[i];
	}

	backtracking(0, 0);

	std::cout << max_num << std::endl;
}