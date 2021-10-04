#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int N;
std::vector<std::pair<int, int>> infos;

bool check(const std::pair<int, int>& t1, const std::pair<int, int>& t2) {
	return t1.second > t2.second;
}


int main() {
	std::cin >> N;
	infos.reserve(N);
	for (int i = 0; i < N; ++i) {
		int pos, height;
		std::cin >> pos >> height;
		infos.push_back(std::make_pair(pos, height));
	}
	std::sort(infos.begin(), infos.end(), check);

	std::deque<std::pair<int, int>> area_set;

	int result = 0;

	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			area_set.push_back(infos[i]);
			result += infos[i].second;
			continue;
		}

		std::pair<int, int>& left = area_set.front();
		std::pair<int, int>& right = area_set.back();

		if (left.second >= infos[i].second && left.first > infos[i].first) {
			result += infos[i].second * (left.first - infos[i].first);
			area_set.push_front(infos[i]);
		}
		if (right.second >= infos[i].second && right.first < infos[i].first) {
			result += infos[i].second * (infos[i].first - right.first);
			area_set.push_back(infos[i]);
		}
	}

	std::cout << result << std::endl;
}