#include <iostream>
#include <queue>
int start, end;
int visited[200002]{ 0 };

int calc(const int& num, const int& mode) {
	if (mode == 0) {
		return 2 * num;
	}
	if (mode == 1) {
		return num + 1;
	}
	if (mode == 2) {
		return num - 1;
	}
}

void bfs(const int& start, const int& end) {
	std::queue<int> check;
	check.push(start);
	visited[start] = 1;
	
	int temp_start;
	int new_start;

	while (check.size()) {
		temp_start = check.front();
		check.pop();
		if (temp_start == end) {
			std::cout << visited[temp_start] - 1 << std::endl;
			return;
		}
		for (int i = 0; i < 3; ++i) {
			new_start = calc(temp_start, i);
			if (new_start >= 0 && new_start < 200002) {
				if (visited[new_start] == 0) {
					visited[new_start] = visited[temp_start] + 1;
					check.push(new_start);
				}
			}
		}
	}
}

int main() {
	std::cin >> start >> end;
	bfs(start, end);
}