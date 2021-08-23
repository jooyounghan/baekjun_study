#include <iostream>
#include <algorithm>

int heights[10000];
int new_heights[10000];
int main(){
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		int num;
		std::cin >> num;
		for (int idx = 0; idx < num; ++idx) {
			std::cin >> heights[idx];
		}
		std::sort(heights, heights + num);

		for (int idx = 0; idx < num; ++idx) {
			if (idx % 2) {
				new_heights[num - (idx + 1) / 2] = heights[idx];
			}
			else {
				new_heights[idx / 2] = heights[idx];
			}
		}
		int max_num = 0;
		for (int idx = 0; idx < num; ++idx) {
			int temp;
			if (idx == num - 1) {
				temp = new_heights[0] - new_heights[idx];
			}
			else {
				temp = new_heights[idx] - new_heights[idx + 1];
			}
			temp < 0 ? temp = -temp : temp = temp;
			if (max_num < temp) {
				max_num = temp;
			}
		}
		std::cout << max_num << std::endl;
	}
}