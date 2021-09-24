#include <iostream>
#include <string>
#include <queue>
#include <vector>

int N;

std::string pictures[100];
bool visited[100][100]{ false };
std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


void check(const int& temp_row, const int& temp_col, const bool& blind_flag) {
	std::queue<std::pair<int, int>> check_queue;
	visited[temp_row][temp_col] = !blind_flag;
	check_queue.push(std::make_pair(temp_row, temp_col));
	char cmpchar = pictures[temp_row][temp_col];

	while (check_queue.size()) {
		int row, col;
		std::pair<int, int>& pix = check_queue.front();
		check_queue.pop();
		row = pix.first;
		col = pix.second;
		for (std::pair<int, int>& direction : directions) {
			int new_row = row + direction.first;
			int new_col = col + direction.second;
			if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) {
				if (visited[new_row][new_col] == blind_flag) {
					if (blind_flag) {
						if (cmpchar == 'B' && pictures[new_row][new_col] == cmpchar) {
							visited[new_row][new_col] = !blind_flag;
							check_queue.push(std::make_pair(new_row, new_col));
						}
						if (cmpchar != 'B' && pictures[new_row][new_col] != 'B') {
							visited[new_row][new_col] = !blind_flag;
							check_queue.push(std::make_pair(new_row, new_col));
						}
					}
					else {
						if (pictures[new_row][new_col] == cmpchar) {
							visited[new_row][new_col] = !blind_flag;
							check_queue.push(std::make_pair(new_row, new_col));
						}
					}
				}
			}
		}
	}
}


int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> pictures[i];
	}

	int check_num = 0;
	int check_blind_num = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] == 0) {
				check(i, j, false);
				check_num += 1;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] == 1) {
				check(i, j, true);
				check_blind_num += 1;
			}
		}
	}
	std::cout << check_num << " " << check_blind_num << std::endl;
}