#include <iostream>
#include <vector>

int N, P;
std::vector<std::vector<int>> guitar;

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> P;
	guitar.resize(7);

	for (int i = 1; i < 7; ++i) {
		guitar[i].reserve(300000);
	}

	int cnt = 0;

	for (int i = 0; i < N; ++i) {
		int line, fret;
		std::cin >> line >> fret;
		while (guitar[line].size() && guitar[line][guitar[line].size() - 1] > fret) {
			guitar[line].pop_back();
			cnt += 1;
		}
		if (guitar[line].size() && guitar[line][guitar[line].size() - 1] == fret) {
			continue;
		}
		else {
			guitar[line].push_back(fret);
			cnt += 1;
		}
	}
	std::cout << cnt << std::endl;
}