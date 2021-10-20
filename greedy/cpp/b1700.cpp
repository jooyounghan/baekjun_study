#include <iostream>
#include <vector>

int N, K;
std::vector<int> multitabs;
int multitabs_interval[101];
std::vector<int> check;
int cnt = 0;

void scheduling(const int& check_idx) {
	std::fill(multitabs_interval, multitabs_interval + 101, 1000);
	int future_temp = check[check_idx];
	for (int i = 0; i < N; ++i) {
		if (future_temp == multitabs[i]) {
			return;
		}
	}

	for (int i = check_idx + 1; i <= K; ++i) {
		future_temp = check[i];
		for (int j = 0; j < N; ++j) {
			if (future_temp == multitabs[j] && multitabs_interval[j] == 1000) {
				multitabs_interval[j] = i - check_idx;
			}
		}
	}
	int max_interval = 0;
	int max_idx = 0;
	for (int i = 0; i < N; ++i) {
		if (max_interval < multitabs_interval[i]) {
			max_interval = multitabs_interval[i];
			max_idx = i;
		}
	}
	multitabs[max_idx] = check[check_idx];
	cnt += 1;
}

int main() {
	std::cin >> N >> K;
	multitabs.reserve(N + 1);
	check.resize(K + 1);
	for (int i = 1; i <= K; ++i) {
		std::cin >> check[i];
	}
	
	for (int check_idx = 1; check_idx <= K; ++check_idx) {
		bool flag = true;
		if (multitabs.size() == N) {
			scheduling(check_idx);
		}
		else {
			for (int i = 0; i < multitabs.size(); ++i) {
				if (check[check_idx] == multitabs[i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				multitabs.push_back(check[check_idx]);
			}
		}
	}

	std::cout << cnt << '\n';
}