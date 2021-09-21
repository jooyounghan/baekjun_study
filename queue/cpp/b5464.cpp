#include <iostream>
#include <vector>
#include <queue>
int N, M;
int prices[100];
int weights[2001];

std::vector<int> parking{ 0 };
std::queue<int> waiting;

int check_available() {
	for (int i = 0; i < parking.size(); ++i) {
		if (parking[i] == 0) {
			return i;
		}
	}
	return -1;
}

int check_where(const int& cars) {
	for (int i = 0; i < parking.size(); ++i) {
		if (parking[i] == -cars) {
			return i;
		}
	}
	return -1;
}

int main() {
	int result = 0;

	std::cin >> N >> M;
	
	parking.resize(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> prices[i];
	}
	for (int i = 1; i < M + 1; ++i) {
		std::cin >> weights[i];
	}
	for (int i = 0; i < 2 * M; ++i) {
		int cars;
		std::cin >> cars;
		if (cars >= 0) {
			int available = check_available();
			if (available >= 0) {
				parking[available] = cars;
			}
			else {
				waiting.push(cars);
			}
		}
		else {
			int parked_place = check_where(cars);
			parking[parked_place] = 0;
			result += prices[parked_place] * weights[-cars];

			if (waiting.size()) {
				int new_car = waiting.front();
				waiting.pop();
				int available = check_available();
				parking[available] = new_car;
			}
		}
	}
	std::cout << result << std::endl;
}