#include <iostream>
int num_list[8];
bool visited[8];
int N;
int max_value = 0;

void backtracking(const int& latter, const int& temp_max_value, const int& cnt) {
	if (cnt == N) {
		if (temp_max_value > max_value) {
			max_value = temp_max_value;
		}
		return;
	}

	if (cnt == 0) {
		for (int i = 0; i < N; ++i) {
			visited[i] = true;
			backtracking(num_list[i], 0, cnt + 1);
			visited[i] = false;
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (visited[i]) {
				continue;
			}
			visited[i] = true;
			int temp_sum = latter - num_list[i];
			temp_sum = temp_sum > 0 ? temp_sum : -temp_sum;
			backtracking(num_list[i], temp_max_value + temp_sum, cnt + 1);
			visited[i] = false;
		}
	}
	return;
}


int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> num_list[i];
	}
	backtracking(0, 0, 0);
	std::cout << max_value << std::endl;
}