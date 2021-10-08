#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

int N, M;
int maps[1000][1000]{ 0 };
int visited[1000][1000][2]{ 0 };
int values[1000][1000]{ 0 };

std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs() {
	std::queue<std::tuple<int, int, int>> check;
	check.push(std::make_tuple(0, 0, 0));
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;
	values[0][0] = 1;
	
	while (check.size()) {

		int row, col, work;
		row = std::get<0>(check.front());
		col = std::get<1>(check.front());
		work = std::get<2>(check.front());
		check.pop();

		for (std::pair<int, int>& dir : directions) {
			int new_row = row + dir.first;
			int new_col = col + dir.second;

			if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M) {
				if (maps[new_row][new_col] == 1) {
					// 벽을 만났을 때
					if (work == 0 && visited[new_row][new_col][1] == 0) {
						// 공사 가능할 때
						visited[new_row][new_col][1] = 1;
						values[new_row][new_col] = values[row][col] + 1;
						check.push(std::make_tuple(new_row, new_col, 1));
					}
				}
				else if (maps[new_row][new_col] == 0) {
					// 벽을 안 만났을 때
					if (visited[new_row][new_col][work] == 0) {
						visited[new_row][new_col][work] = 1;
						values[new_row][new_col] = values[row][col] + 1;
						check.push(std::make_tuple(new_row, new_col, work));
					}
				}
			}
			if (new_row == N - 1 && new_col == M - 1) {
				return;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		std::string temp;
		std::cin >> temp;
		for (int j = 0; j < M; ++j) {
			maps[i][j] = temp[j] - '0';
		}
	}

	bfs();
	if (values[N - 1][M - 1] == 0) {
		values[N - 1][M - 1] = -1;
	}
	std::cout << values[N - 1][M - 1] << std::endl;
}