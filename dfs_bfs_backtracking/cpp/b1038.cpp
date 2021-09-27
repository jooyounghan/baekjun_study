#include <iostream>
#include <string>
#include <queue>

int N;
int cnt = -1;

void bfs(const int& target) {
	std::queue<std::string> decrease;
	for (int i = 0; i < 10; ++i) {
		decrease.push(std::string{ (char)('0' + i) });
	}

	while (decrease.size()) {
		std::string temp_string = decrease.front();
		cnt += 1;

		if (cnt == target) {
			std::cout << temp_string << std::endl;
			return;
		}

		decrease.pop();
		for (int i = 0; i < temp_string[temp_string.size() - 1] - '0'; ++i) {
			decrease.push(temp_string + char('0' + i));
		}
	}
	std::cout << -1 << std::endl;
}


int main() {
	std::cin >> N;
	bfs(N);
}