#include <iostream>
#include <vector>
int t;
int n;
int n1, n2;

void get_ancestor(const int(&node)[10001], std::vector<int>& temp_ancestor, const int& n) {
	if (node[n] == 0) {
		return;
	}
	temp_ancestor.push_back(node[n]);
	get_ancestor(node, temp_ancestor, node[n]);
	return;
}

int main() {
	std::cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		int node[10001]{ 0 };

		std::cin >> n;
		for (int i = 1; i < n; ++i) {
			int parent, child;
			std::cin >> parent >> child;
			node[child] = parent;
		}
		std::cin >> n1 >> n2;
		std::vector<int> n1_parent{ n1 };
		get_ancestor(node, n1_parent, n1);
		std::vector<int> n2_parent{ n2 };
		get_ancestor(node, n2_parent, n2);
		int idx = 1;
		while (true) {
			if (int(n1_parent.size()) - idx < 0 || int(n2_parent.size()) - idx < 0 || n1_parent[n1_parent.size() - idx] != n2_parent[n2_parent.size() - idx]){
				break;
			}
			idx++;
		}
		std::cout << n1_parent[n1_parent.size() - idx + 1] << std::endl;
	}
}