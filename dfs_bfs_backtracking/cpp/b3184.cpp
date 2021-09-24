#include <iostream>
#include <string>
#include <vector>
#include <stack>

int R, C;
std::vector<std::string> fields;
bool visited[250][250]{ 0 };

std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void dfs(const int& row, const int& col, int& sheeps, int& wolves) {
	std::stack<std::pair<int, int>> stacks;
	stacks.push({ row, col });
	visited[row][col] = true;
	while (stacks.size()) {
		std::pair<int, int> check = stacks.top();
		stacks.pop();

		int& temp_row = check.first;
		int& temp_col = check.second;

		if (fields[temp_row][temp_col] == 'v') { wolves += 1; }		
		if (fields[temp_row][temp_col] == 'o') { sheeps += 1; }

		for (std::pair<int, int>& direction : directions) {
			if (temp_row + direction.first >= 0 &&
				temp_row + direction.first < R &&
				temp_col + direction.second >= 0 &&
				temp_col + direction.second < C &&
				!visited[temp_row + direction.first][temp_col + direction.second] &&
				fields[temp_row + direction.first][temp_col + direction.second] != '#') {
				visited[temp_row + direction.first][temp_col + direction.second] = true;
				stacks.push({ temp_row + direction.first, temp_col + direction.second });
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> R >> C;
	fields.resize(R);

	for (int i = 0; i < R; ++i) {
		std::cin >> fields[i];
	}
	
	int sheeps = 0;
	int wolves = 0;

	for (int row = 0; row < R; ++row) {
		for (int col = 0; col < C; ++col) {
			if (fields[row][col] == '.' || fields[row][col] == 'o' || fields[row][col] == 'v') {
				if (!visited[row][col]) {
					int temp_sheeps = 0;
					int temp_wolves = 0;
					dfs(row, col, temp_sheeps, temp_wolves);
					temp_sheeps = temp_sheeps > temp_wolves ? temp_sheeps : 0;
					temp_wolves = temp_sheeps > temp_wolves ? 0 : temp_wolves;
					sheeps += temp_sheeps;
					wolves += temp_wolves;
				}
			}
		}
	}

	std::cout << sheeps << " " << wolves << std::endl;
}