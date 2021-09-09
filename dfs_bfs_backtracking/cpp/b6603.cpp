#include <iostream>

int lotto[13];
bool visited[13];
int k;

void backtracking(const int& pos, const int& cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 13; ++i) {
			if (visited[i]) {
				std::cout << lotto[i] << " ";
			}
		}
		std::cout << "\n";
		return;
	}

	if (pos >= k) {
		return;
	}

	visited[pos] = 1;
	backtracking(pos + 1, cnt + 1);
	visited[pos] = 0;
	backtracking(pos + 1, cnt);
	return;
}


int main() {
	int times = 0;
	while (true) {
		std::cin >> k;
		if (k == 0) {
			break;
		}
		if (times) {
			std::cout << "\n";
		}
		times++;
		for (int i = 0; i < k; ++i) {
			std::cin >> lotto[i];
			visited[i] = 0;
		}
		backtracking(0, 0);
	}
}