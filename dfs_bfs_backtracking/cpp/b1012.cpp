#include <iostream>
#include <vector>
#include <queue>
int T;
int N, M, K;

std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs(const int& row, const int& col, bool(&maps)[50][50]) {
	std::queue<std::pair<int, int>> check_cabbage;
	check_cabbage.push(std::make_pair(row, col));
	maps[row][col] = false;
	int temp_x, temp_y;
	int new_x, new_y;
	while (check_cabbage.size()) {
		temp_x = check_cabbage.front().first;
		temp_y = check_cabbage.front().second;
		check_cabbage.pop();
		for (std::pair<int, int>& dir : directions) {
			new_x = temp_x + dir.first;
			new_y = temp_y + dir.second;
			if (0 <= new_x && new_x < M && 0 <= new_y && new_y < N && maps[new_x][new_y]) {
				maps[new_x][new_y] = false;
				check_cabbage.push(std::make_pair(new_x, new_y));
			}
		}
	}
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		std::cin >> M >> N >> K;
		bool maps[50][50]{ false };
		std::queue<std::pair<int, int>> check;
		int x, y;
		for (int i = 0; i < K; ++i) {
			std::cin >> x >> y;
			check.push(std::make_pair(x, y));
			maps[x][y] = true;
		}
		int cnt = 0;
		while (check.size()) {
			x = check.front().first;
			y = check.front().second;
			check.pop();
			if (maps[x][y] == true) {
				cnt += 1;
				bfs(x, y, maps);
			}
		}
		std::cout << cnt << '\n';
	}
}