#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int book_pos[50];
std::vector<int> positive_move;
std::vector<int> negative_move;
std::vector<int> move;
int cnt = 0;

void set_move() {
	int idx = 0;
	while (idx < negative_move.size()) {
		move.push_back(negative_move[idx]);
		idx += M;
	}

	idx = positive_move.size() - 1;
	while (idx >= 0) {
		move.push_back(positive_move[idx]);
		idx -= M;
	}
}

void get_move() {
	int max_move = 0;
	int max_idx = 0;
	for (int i = 0; i < move.size(); ++i) {
		if (abs(move[i]) > max_move) {
			max_move = abs(move[i]);
			max_idx = i;
		}
	}

	for (int i = 0; i < move.size(); ++i) {
		if (i == max_idx) {
			cnt += max_move;
			continue;
		}
		cnt += abs(move[i]) * 2;
	}
}

int main() {
	std::cin >> N >> M;
	positive_move.reserve(N);
	negative_move.reserve(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> book_pos[i];
	}

	std::sort(book_pos, book_pos + N);
	
	for (int i = 0; i < N; ++i) {
		if (book_pos[i] > 0) {
			positive_move.push_back(book_pos[i]);
		}
		else {
			negative_move.push_back(book_pos[i]);
		}
	}
	set_move();
	get_move();

	std::cout << cnt << '\n';
}