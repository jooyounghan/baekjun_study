#include <iostream>
#include <vector>
#include <algorithm>

int first[123];
int second[123];
int position[124]{ 0 };
std::vector<int*> bars{ first, second };

int main()
{
	int K;
	std::cin >> K;

	for (int idx = 0; idx < K; ++idx) {
		std::cin >> first[idx];
	}

	int cnt = 0;
	std::vector<std::pair<int, int>> stack;

	int first_top_idx = K - 1;
	int second_top_idx = -1;
	std::vector<int*> idx{ &first_top_idx, &second_top_idx };

	for (int i = K; i > 0; --i) {
		int* main_bar = bars[position[i]];
		int* sub_bar = bars[!position[i]];
		int* main_idx_ptr = idx[position[i]];
		int* sub_idx_ptr = idx[!position[i]];
		while (main_bar[*main_idx_ptr] < i) {
			stack.push_back(std::pair<int, int>{position[i] + 1, !position[i] + 1});
			cnt++;
			int temp = main_bar[*main_idx_ptr];
			*sub_idx_ptr += 1;
			sub_bar[*sub_idx_ptr] = temp;
			position[temp] = !position[temp];
			main_bar[*main_idx_ptr] = 0;
			*main_idx_ptr -= 1;
		}
		stack.push_back(std::pair<int, int>{position[i] + 1, 3});
		cnt++;
		main_bar[*main_idx_ptr] = 0;
		*main_idx_ptr -= 1;
	}
	std::cout << cnt << "\n";
	for (int i = 0; i < stack.size(); ++i) {
		std::cout << stack[i].first << " " << stack[i].second << "\n";
	}
}