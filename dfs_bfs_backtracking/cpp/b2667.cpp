#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

void bfs(std::vector<std::string>& house_map, const int& N) {
	int num_group = 0;
	std::vector<int> num_houses;

	std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			if (house_map[row][col] == '1') {
				int temp_num = 0;
				num_group += 1;
				std::stack<std::pair<int, int>> check_stack;
				check_stack.push({ row, col });
				house_map[row][col] = '0';
				while (check_stack.size()) {
					temp_num += 1;
					std::pair<int, int> check = check_stack.top();
					check_stack.pop();
					int& check_row = check.first;
					int& check_col = check.second;
					for (std::pair<int, int>& direction : directions) {
						int new_row = check_row + direction.first;
						int new_col = check_col + direction.second;
						if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N && house_map[new_row][new_col] == '1') {
							house_map[new_row][new_col] = '0';
							check_stack.push({ new_row, new_col });
						}
					}
				}
				num_houses.push_back(temp_num);
			}	
		}
	}
	std::cout << num_group << std::endl;
	std::sort(num_houses.begin(), num_houses.end());
	for (int i = 0; i < num_houses.size(); ++i) {
		std::cout << num_houses[i] << std::endl;
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<std::string> house_map;
	house_map.resize(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> house_map[i];
	}

	bfs(house_map, N);
}