#include <iostream>
#include <queue>
#include <vector>

int N, M;
int result = 1;
int boxes[1000][1000];

std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs(int& result, std::vector<std::pair<int, int>>& tomatoes) {
	std::queue<std::pair<int, int>> check;
	for (std::pair<int, int>& tomato : tomatoes) {
		check.push(tomato);
	}

	while (check.size()) {
		int row = check.front().first;
		int col = check.front().second;
		check.pop();
		for (std::pair<int, int>& direction : directions) {
			int new_row = row + direction.first;
			int new_col = col + direction.second;
			if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M && !boxes[new_row][new_col]) {
				boxes[new_row][new_col] = boxes[row][col] + 1;
				check.push(std::make_pair(new_row, new_col));
				result = boxes[new_row][new_col] > result ? boxes[new_row][new_col] : result;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> M >> N;
	
	std::vector<std::pair<int, int>> tomatoes;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> boxes[i][j];
			if (boxes[i][j] == 1) {
				tomatoes.push_back(std::make_pair(i, j));
			}
		}
	}

	bfs(result, tomatoes);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (boxes[i][j] == 0) {
				std::cout << -1 << std::endl;
				return 0;
			}
		}
	}
	std::cout << result - 1 << std::endl;
	return 0;
}