#include <iostream>

int N, K;
int weights[8];
bool used[8]{ false };
int possible = 0;

void backtracking(const int& cnt, const int& rest) {
	if (cnt == N) {
		possible += 1;
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (used[i] == false && rest + weights[i] - K >= 0) {
			used[i] = true;
			backtracking(cnt + 1, rest + weights[i] - K);
			used[i] = false;
		}
	}
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		std::cin >> weights[i];
	}
	backtracking(0, 0);
	std::cout << possible << std::endl;
}