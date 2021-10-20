#include <iostream>
#include <vector>
int N;
unsigned long long D = 0;
unsigned long long G = 0;
bool visited[300001]{ false };
unsigned long long combinations[300001][4]{ 0 };
std::vector<std::vector<int>> adj;

int nC3(const int& n) {
	return n * (n - 1) * (n - 2) / 6;
}

void count(const int& node) {
	visited[node] = true;
	if (adj[node].size() == 0 || adj[node].size() == 1) {
		return;
	}
	if (adj[node].size() > 2) {
		G += nC3(adj[node].size());
	}
	for (auto& adj_node : adj[node]) {
		if (visited[adj_node] == false) {
			D += (unsigned long long)(adj[node].size() - 1) * (unsigned long long)(adj[adj_node].size() - 1);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	combinations[1][0] = 1;
	combinations[1][1] = 1;
	std::cin >> N;
	adj.resize(N + 1);
	int temp1, temp2;
	for (int i = 0; i < N - 1; ++i) {
		std::cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	for (int i = 1; i < N + 1; ++i) {
		if (visited[i] == false) {
			count(i);
		}
	}

	if (D > 3 * G) std::cout << 'D' << '\n';
	else if (D < 3 * G) std::cout << 'G' << '\n';
	else std::cout << "DUDUDUNGA" << '\n';
}