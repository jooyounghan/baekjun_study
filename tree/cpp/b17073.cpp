#include <iostream>
using namespace std;

int n, w;
int node[500001]{ 0 };

int main() {

	int node1, node2;
	double leaf = 0;
	double result;
	std::cin >> n >> w;

	for (int i = 0; i < n - 1; i++) {
		std::cin >> node1 >> node2;
		node[node1]++;
		node[node2]++;
	}

	for (int i = 2; i <= n + 1; i++) {
		if (node[i] == 1)
			leaf += 1;
	}

	result = w / leaf;

	std::cout.precision(6);
	std::cout << std::fixed << result << std::endl;

}