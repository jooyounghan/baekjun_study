#include <iostream>

int N, L, R, X;
int cnt = 0;
int problems[15];

void backtracking(const int& pos, const int& temp_min, const int& temp_max, const int& temp_sum) {
	if (pos == N) {
		if (temp_max - temp_min >= X && L <= temp_sum && R >= temp_sum) {
			cnt += 1;
		}
		return;
	}

	if (pos > 0 && temp_sum > R) {
		return;
	}
	
	backtracking(pos + 1, std::min(temp_min, problems[pos]), std::max(temp_max, problems[pos]), temp_sum + problems[pos]);
	backtracking(pos + 1, temp_min, temp_max, temp_sum);
}

int main() {
	std::cin >> N >> L >> R >> X;
	for (int i = 0; i < N; ++i) {
		std::cin >> problems[i];
	}
	backtracking(0, 10E6, 0, 0);
	std::cout << cnt << std::endl;
}