#include <iostream>
#include <vector>

int N;
int removal;
int root;
int nodes_visited[50];
std::vector<std::vector<int>> nodes;

int cnt = 0;

void cnt_leaf(const int& start, const int& removal) {
	int temp_num = 0;
	for (int i = 0; i < nodes[start].size(); ++i) {
		if (nodes_visited[nodes[start][i]]) {
			continue;
		}
		cnt_leaf(nodes[start][i], removal);
		temp_num += 1;
	}
	if (temp_num) return;
	else cnt += 1; return;
}

int main() {
	std::cin >> N;
	nodes.resize(N);

	for (int i = 0; i < N; ++i) {
		int temp_nodes;
		std::cin >> temp_nodes;
		if (temp_nodes == -1) {
			root = i;
			continue;
		}
		nodes[temp_nodes].push_back(i);
	}
	std::cin >> removal;
	nodes_visited[removal] = 1;

	if (removal == root) {
		std::cout << 0 << std::endl;
	}
	else {
		cnt_leaf(root, removal);
		std::cout << cnt << std::endl;
	}	
}