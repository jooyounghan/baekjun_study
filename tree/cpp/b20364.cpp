#include <iostream>
#include <vector>
int is_possible(int& start, bool*& node) {
	int  idx = start;
	std::vector<int > child_set;
	while (idx > 0) {
		child_set.push_back(idx);
		idx = idx / 2;
	}
	idx = child_set.size() - 1;

	while (idx >= 0) {
		if (node[child_set[idx]]) {
			return child_set[idx];
		}
		idx -= 1;
	}
	node[start] = 1;
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int  N;
	int Q;
	std::cin >> N >> Q;
	bool* node = new bool[N + 1]{ 0 };
	for (int i = 0; i < Q; ++i) {
		int land;
		std::cin >> land;
		std::cout << is_possible(land, node) << "\n";
	}
	delete[] node;
}
