#include<iostream>
#include <string>
#include <vector>
#include <queue>

bool visited[100][100];

void check_tile(std::vector<std::string>& floor_status, const int& r, const int& c) {
	int row, col;
	int cnt = 0;
	row = floor_status.size();
	col = floor_status[0].size();
	if (floor_status[r][c] == '-') {
		int idx = 0;
		while (c + idx < col && floor_status[r][c + idx] == '-') {
			visited[r][c + idx] = true;
			idx += 1;
		}
	}
	else {
		int idx = 0;
		while (r + idx < row && floor_status[r + idx][c] == '|') {
			visited[r + idx][c] = true;
			idx += 1;
		}
	}
}

int count_tile(std::vector<std::string>& floor_status) {
	int row, col;
	int cnt = 0;
	row = floor_status.size();
	col = floor_status[0].size();
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			if (!visited[r][c]) {
				cnt += 1;
				check_tile(floor_status, r, c);
			}
		}
	}
	return cnt;
}



int main() {
	int row, col;
	std::vector<std::string> floor_status;

	std::cin >> row >> col;
	floor_status.resize(row);

	for (int r = 0; r < row; ++r) {
		std::cin >> floor_status[r];
	}

	int cnt = count_tile(floor_status);
	std::cout << cnt << std::endl;
}