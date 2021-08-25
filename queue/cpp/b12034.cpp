#include <iostream>
#include <deque>

unsigned int cmp_queue[200];
unsigned int result[100];

int main() {
	int T;
	std::cin >> T;
	for (int tc = 1; tc < T + 1; ++tc) {
		int N;
		std::cin >> N;

		int cmp_idx = 0;
		int cmp_insert_idx = 0;
		for (int i = 0; i < N * 2; ++i) {
			unsigned int temp;
			std::cin >> temp;
			if (i == 0) {
				cmp_queue[cmp_insert_idx] = temp;
				cmp_insert_idx++;
				continue;
			}
			if ((cmp_queue[cmp_idx] * 4 / 3) == temp) {
				result[cmp_idx] = cmp_queue[cmp_idx];
				cmp_idx++;
			}
			else {
				cmp_queue[cmp_insert_idx] = temp;
				cmp_insert_idx++;
			}
		}
		

		std::cout << "Case #" << tc << ": ";
		for (int idx = 0; idx < N; ++idx) {
			std::cout << result[idx] << " ";
		}
		std::cout << "\n";
	}
}