#include<iostream>
#include<vector>
#include<stack>

std::vector<std::vector<int>> connections;

int count_infection(std::vector<std::vector<int>>& connections) {
	int cnt = 0;
	int infected[101]{ 0 };

	std::stack<int> check_stack;
	check_stack.push(1);
	infected[1] = 1;

	while (check_stack.size() > 0) {
		cnt += 1;
		int check_node = check_stack.top();
		check_stack.pop();
		for (int& connect : connections[check_node]) {
			if (!infected[connect]) {
				check_stack.push(connect);
				infected[connect] = 1;
			}
		}
	}
	return cnt - 1;
}

int main() {
	int N;
	std::cin >> N;
	connections.resize(N + 1);

	int connect;
	std::cin >> connect;
	for (int i = 0; i < connect; ++i) {
		int temp_a, temp_b;
		std::cin >> temp_a >> temp_b;
		connections[temp_a].push_back(temp_b);
		connections[temp_b].push_back(temp_a);
	}
	
	std::cout << count_infection(connections) << std::endl;
}