#include <iostream>
#include <vector>
int T;
int N;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		std::cin >> N;
		std::vector<int> left;
		left.reserve(N);
		int temp;
		for (int i = 0; i < N; ++i) {
			std::cin >> temp;
			bool flag = false;
			for (int j = 0; j < left.size(); ++j) {
				if (left[j] + 500 == temp) {
					flag = true;
					break;
				}
			}
			if (flag) continue;
			left.push_back(temp);
		}
		int result = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> temp;
			for (int j = 0; j < left.size(); ++j) {
				if (left[j] + 1500 == temp) {
					result++;
					break;
				}
			}
		}
		std::cout << result << "\n";
	}
}