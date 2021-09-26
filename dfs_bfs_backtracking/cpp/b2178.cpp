#include <iostream>
#include <string>
#include <vector>
#include <queue>

int N, M;
int fields[100][100];
std::vector<std::pair<int, int>> directions { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs() {
	std::queue<std::pair<int, int>> check;
	check.push(std::make_pair(0, 0));
	
	while (check.size()) {
		int row = check.front().first;
		int col = check.front().second;
		if (row == N - 1 && col == M - 1) {
			std::cout << fields[row][col] << std::endl;
			return;
		}
		check.pop();
		for (std::pair<int, int>& direction : directions) {
			int new_row = row + direction.first;
			int new_col = col + direction.second;
			if (new_row == 0 && new_col == 0) { continue; }
			if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M && fields[new_row][new_col] == 1) {
				check.push(std::make_pair(new_row, new_col));
				fields[new_row][new_col] = fields[row][col] + 1;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		std::string temp;
		std::cin >> temp;
		for (int j = 0; j < M; ++j) {
			fields[i][j] = temp[j] - '0';
		}
	}
	bfs();
}
