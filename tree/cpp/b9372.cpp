#include <iostream>
int T;
int N, M;

int main() {
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		std::cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			int temp1, temp2;
			std::cin >> temp1 >> temp2;
		}
		std::cout << N - 1 << "\n";
	}
}