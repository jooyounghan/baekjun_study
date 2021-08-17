#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> heights;
	heights.reserve(100000);
	for (int i = 0; i < N; ++i) {
		int temp;
		std::cin >> temp;
		if (i == 0) {
			heights.push_back(temp);
		}
		else {
			while (heights[heights.size() - 1] <= temp) {
				heights.pop_back();
				if (heights.size() == 0) {
					break;
				}
			}
			heights.push_back(temp);
		}
	}
	std::cout << heights.size() << std::endl;
}