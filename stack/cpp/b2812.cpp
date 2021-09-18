#include <iostream>
#include <string>
#include <vector>
int N, K;
std::string numbers;
std::vector<char> result;

int main() {
	std::cin >> N >> K;
	std::cin >> numbers;

	int cnt = N - K;
	result.reserve(cnt);
	result.push_back(numbers[0]);
	numbers.erase(numbers.begin());
	for (auto& number : numbers) {
		while (K and result.size() and number > result[result.size() - 1]) {
			result.pop_back();
			K--;
		}
		if (result.size() < cnt) {
			result.push_back(number);
			continue;
		}
		break;
	}
	for (int i = 0; i < result.size(); ++i) {
		std::cout << result[i];
	}
}