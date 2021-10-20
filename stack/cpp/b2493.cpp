#include <iostream>
#include <stack>

int N;
int transmission[500001]{ 0 };
int top = -1;
std::pair<int, int> check[500000];

int main() {
	std::cin >> N;
	int temp;
	for (int i = 1; i < N + 1; ++i) {
		std::cin >> temp;
		
		if (top == -1) {
			top += 1;
			check[top] = std::make_pair(temp, i);
			continue;
		}
		
		if (check[top].first > temp) {
			transmission[i] = check[top].second;
			top += 1;
			check[top] = std::make_pair(temp, i);
		}
		else {
			while (top > -1 && check[top].first <= temp) {
				top -= 1;
			}
			if (top > -1) {
				transmission[i] = check[top].second;
			}
			top += 1;
			check[top] = std::make_pair(temp, i);
		}
	}

	for (int i = 1; i < N + 1; ++i) {
		std::cout << transmission[i] << ' ';
	}
}