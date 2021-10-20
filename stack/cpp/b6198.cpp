#include <iostream>
#include <stack>
int N;
unsigned int cnt = 0;
std::stack<int> heights;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;
	int temp;
	for (int i = 0; i < N; ++i) {
		std::cin >> temp;
		if (heights.size() == 0) {
			heights.push(temp);
			continue;
		}

		if (heights.top() > temp) {
			heights.push(temp);
			cnt += heights.size() - 1;
		}
		else {
			while (heights.size() > 0 && heights.top() <= temp) {
				heights.pop();
			}
			heights.push(temp);
			cnt += heights.size() - 1;
		}
	}

	std::cout << cnt << '\n';
}