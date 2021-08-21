#include <iostream>
#include <vector>


int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> circle;
	circle.resize(N);
	for (int i = 0; i < N; ++i) {
		circle[i] = i + 1;
	}

	std::vector<int> Josephus;
	int start_idx = 0;
	int interval = K - 1;
	while (Josephus.size() < N) {
		start_idx = (start_idx + interval) % circle.size();
		Josephus.push_back(circle[start_idx]);
		circle.erase(circle.begin() + start_idx);
	}
	
	std::cout << "<";
	for (int i = 0; i < N; ++i) {
		if (i == N - 1) {
			std::cout << Josephus[i] << ">" << std::endl;
			continue;
		}
		std::cout << Josephus[i] << ", ";
	}
}