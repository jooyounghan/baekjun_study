#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int square[100][100]{ 0 };

void dfs(int& area_num, std::vector<int>& area_value, const std::pair<int, int>& row_col) {
	const int& row = row_col.first;
	const int& col = row_col.second;

	std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			if (!square[r][c]) {
				area_num++;
				int temp_value = 0;
				std::stack<std::pair<int, int>> check_stack;
				check_stack.push({ r, c });
				square[r][c] = 1;
				while (check_stack.size()) {
					temp_value++;
					std::pair<int, int> check_row_col = check_stack.top();
					check_stack.pop();
					int& check_row = check_row_col.first;
					int& check_col = check_row_col.second;

					for (std::pair<int, int>& direction : directions) {
						int new_row = check_row + direction.first;
						int new_col = check_col + direction.second;
						if (0 <= new_row && new_row < row && 0 <= new_col && new_col < col && !square[new_row][new_col]) {
							check_stack.push({ new_row, new_col });
							square[new_row][new_col] = 1;
						}
					}

				}
				area_value.push_back(temp_value);
			}
		}
	}
}

int main() {
	int row, col, k;
	std::cin >> row >> col >> k;
	for (int i = 0; i < k; ++i) {
		int left_row, left_col, right_row, right_col;
		std::cin >> left_col >> left_row >> right_col >> right_row;
		for (int r = left_row; r < right_row; ++r) {
			for (int c = left_col; c < right_col; ++c) {
				square[r][c] = 1;
			}
		}
	}

	int area_num = 0;
	std::vector<int> area_value;
	dfs(area_num, area_value, std::pair<int, int>{row, col});
	std::cout << area_num << std::endl;
	std::sort(area_value.begin(), area_value.end());
	for (int i = 0; i < area_value.size(); ++i) {
		std::cout << area_value[i] << " ";
	}
	std::cout << std::endl;
}