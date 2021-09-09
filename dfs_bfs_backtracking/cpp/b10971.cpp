#include <iostream>

int N;
int visited[10];
int prices[10][10];
int min_value = 10000000;

void backtracking(const int& cnt, const int& pos, const int& target, const int& temp_val) {
	if (cnt == N) {
		if (prices[pos][target]) {
			if (temp_val + prices[pos][target] < min_value) {
				min_value = temp_val + prices[pos][target];
			}
		}
		return;
	}

	if (temp_val > min_value) {
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (prices[pos][i] && !visited[i]){
			visited[i] = 1;
			backtracking(cnt + 1, i, target, temp_val + prices[pos][i]);
			visited[i] = 0;
		}
	}
}


int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> prices[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		visited[i] = 1;
		backtracking(1, i, i, 0);
		visited[i] = 0;
	}
	std::cout << min_value << std::endl;
}