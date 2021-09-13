#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> trees;

void preorder(std::vector<std::vector<int>>& trees, const int& v_in) {
	std::cout << char(v_in + 64);
	if (trees[v_in][0] > 0) {
		preorder(trees, trees[v_in][0]);
	}

	if (trees[v_in][1] > 0) {
		preorder(trees, trees[v_in][1]);
	}
}

void inorder(std::vector<std::vector<int>>& trees, const int& v_in) {
	if (trees[v_in][0] > 0) {
		inorder(trees, trees[v_in][0]);
	}

	std::cout << char(v_in + 64);

	if (trees[v_in][1] > 0) {
		inorder(trees, trees[v_in][1]);
	}
}

void postorder(std::vector<std::vector<int>>& trees, const int& v_in) {
	if (trees[v_in][0] > 0) {
		postorder(trees, trees[v_in][0]);
	}

	if (trees[v_in][1] > 0) {
		postorder(trees, trees[v_in][1]);
	}

	std::cout << char(v_in + 64);
}

int main() {
	std::cin >> N;
	trees.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		char parent, child1, child2;
		std::cin >> parent >> child1 >> child2;
		trees[int(parent) - 64].push_back(int(child1) - 64);
		trees[int(parent) - 64].push_back(int(child2) - 64);
	}
	preorder(trees, 1);
	std::cout << "\n";
	inorder(trees, 1);
	std::cout << "\n";
	postorder(trees, 1);
	std::cout << "\n";
}