#include <iostream>
#include <vector>
#include <algorithm>

int N, T;
std::vector<int> grade;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> N;
		
		std::vector<int> result;
		result.reserve(N);
		grade.resize(N + 1);

		for (int j = 0; j < N; ++j) {
			int g1, g2;
			std::cin >> g1 >> g2;
			grade[g1] = g2;
		}

		int cnt = 1;
		int cmp_int = grade[1];
		for (int j = 2; j < N + 1; ++j) {
			if (cmp_int > grade[j]) {
				cmp_int = grade[j];
				cnt += 1;
			}
		}
		std::cout << cnt << "\n";
	}
}