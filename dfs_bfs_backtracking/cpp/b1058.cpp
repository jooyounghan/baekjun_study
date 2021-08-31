#include <iostream>
#include <string>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>>& connections, const int& N, int& max_num) {
	for (int person = 0; person < N; ++person) {
		int temp_max_num = 0;
		int visited[50]{ 0 };

		std::queue<int> check_queue;
		check_queue.push(person);
		visited[person] = 1;

		while (check_queue.size()) {
			int check_person = check_queue.front();
			check_queue.pop();

			if (visited[check_person] > 1) {
				temp_max_num += 1;
				if (visited[check_person] == 3) {
					continue;
				}
			}

			for (int& connection : connections[check_person]) {
				if (!visited[connection]) {
					check_queue.push(connection);
					visited[connection] = visited[check_person] + 1;
				}
			}
		}

		if (temp_max_num > max_num) {
			max_num = temp_max_num;
		}
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> connections;
	connections.resize(N);
	for (int i = 0; i < N; ++i) {
		std::string temp_connections;
		std::cin >> temp_connections;
		for (int idx = 0; idx < temp_connections.size(); ++idx) {
			if (temp_connections[idx] == 'Y') {
				connections[i].push_back(idx);
			}
		}
	}

	int max_num = 0;
	bfs(connections, N, max_num);
	std::cout << max_num << std::endl;
}