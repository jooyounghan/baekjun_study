#include <iostream>
#include <algorithm>
int ropes[100000];

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> ropes[i];
	}
	std::sort(ropes, ropes + N);
	int max_num = 0;
	for (int i = 0; i < N; ++i) {
		int temp = ropes[i] * (N - i);
		if (max_num < temp) {
			max_num = temp;
		}
	}

	std::cout << max_num << std::endl;
}