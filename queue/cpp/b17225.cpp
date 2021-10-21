#include <iostream>
#include <deque>

int B, R, N;
int B_num, R_num = 0;
std::deque<int> blue_queue;
std::deque<int> red_queue;
int B_present[100001];
int R_present[100001];
int blue_idx = 0;
int red_idx = 0;

void check_queue() {
	int cnt = 1;
	while (blue_queue.size() && red_queue.size()) {
		if (blue_queue.front() <= red_queue.front()) {
			blue_queue.pop_front();
			B_present[blue_idx] = cnt;
			blue_idx++;
			cnt++;
		}
		else {
			red_queue.pop_front();
			R_present[red_idx] = cnt;
			red_idx++;
			cnt++;
		}
	}
	while (blue_queue.size()) {
		blue_queue.pop_front();
		B_present[blue_idx] = cnt;
		blue_idx++;
		cnt++;
	}
	while (red_queue.size()) {
		red_queue.pop_front();
		R_present[red_idx] = cnt;
		red_idx++;
		cnt++;
	}
}

void make_queue(std::deque<int>& color_queue, const int& color_interval, const int& start, const int& present_num) {
	if (color_queue.size() == 0 || color_queue.back() + color_interval < start) {
		for (int j = 0; j < present_num; ++j) {
			color_queue.push_back(start + j * color_interval);
		}
	}
	else {
		int temp_start = color_queue.back() + color_interval;
		for (int j = 0; j < present_num; ++j) {
			color_queue.push_back(temp_start + j * color_interval);
		}
	}
}

int main() {
	std::cin >> B >> R >> N;
	int start, present_num;
	char color;
	for (int i = 0; i < N; ++i) {
		std::cin >> start >> color >> present_num;
		if (color == 'B') {
			B_num += present_num;
			make_queue(blue_queue, B, start, present_num);
		}
		else {
			R_num += present_num;
			make_queue(red_queue, R, start, present_num);
		}
	}

	check_queue();
	
	std::cout << B_num << '\n';
	for (int i = 0; i < B_num; ++i) {
		std::cout << B_present[i] << ' ';
	}
	std::cout << '\n';

	std::cout << R_num << '\n';
	for (int i = 0; i < R_num; ++i) {
		std::cout << R_present[i] << ' ';
	}
	std::cout << '\n';
}