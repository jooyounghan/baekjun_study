#include <iostream>
#include <vector>
#include <stack>

int maps[50][50];
int W, H;
std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };

void dfs(const int& row, const int& col, std::vector<std::vector<bool>>& visited) {

	std::stack<std::pair<int, int>> check;
	check.push(std::make_pair(row, col));
	visited[row][col] = true;

	int temp_row, temp_col;
	while (check.size()) {
		temp_row = check.top().first;
		temp_col = check.top().second;
		check.pop();
		for (std::pair<int, int>& direction : directions) {
			int new_row = temp_row + direction.first;
			int new_col = temp_col + direction.second;
			if (new_row >= 0 && new_row < H && new_col >= 0 && new_col < W) {
				if (!visited[new_row][new_col] && maps[new_row][new_col]) {
					visited[new_row][new_col] = true;
					check.push(std::make_pair(new_row, new_col));
				}
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	while (true) {

		std::cin >> W >> H;
		if (W == 0 && H == 0) break;

		std::vector<std::vector<bool>> visited;

		visited.resize(H);
		for (int i = 0; i < H; ++i) {
			visited[i].resize(W);
			for (int j = 0; j < W; ++j) {
				std::cin >> maps[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (!visited[i][j] && maps[i][j]) {
					cnt += 1;
					dfs(i, j, visited);
				}
			}
		}
		std::cout << cnt << "\n";
	}
}