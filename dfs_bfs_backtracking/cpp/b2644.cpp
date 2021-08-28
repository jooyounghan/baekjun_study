#include <iostream>
#include <vector>
#include <queue>

int BFS(std::vector<std::vector<int>>& relation_list, std::vector<int> visited, const int& start, const int& target) {
	int cnt = 0;

	std::queue<int> check_queue;
	check_queue.push(start);
	visited[start] = 1;
	while (check_queue.size()) {
		int check_node = check_queue.front();
		check_queue.pop();
		if (check_node == target) {
			return visited[check_node] - 1;
		}

		for (int i = 0; i < relation_list[check_node].size(); ++i) {
			int& new_check_node = relation_list[check_node][i];
			if (!visited[new_check_node]) {
				visited[new_check_node] = visited[check_node] + 1;
				check_queue.push(new_check_node);
			}
		}
	}
	return -1;
}

int main() {
	int N;
	std::cin >> N;
	int start, end;
	std::cin >> start >> end;
	int relations;
	std::cin >> relations;

	std::vector<std::vector<int>> relation_list;
	relation_list.resize(N + 1);

	for (int i = 0; i < relations; ++i) {
		int temp_start, temp_end;
		std::cin >> temp_start >> temp_end;
		relation_list[temp_start].push_back(temp_end);
		relation_list[temp_end].push_back(temp_start);
	}

	std::vector<int> visited;
	visited.resize(N + 1);
	
	std::cout << BFS(relation_list, visited, start, end) << std::endl;
}