#include <iostream>
#include <deque>

int main() {
	int N;
	std::cin >> N;
	
	std::deque<int> cards;
	for (int i = 1; i < N + 1; ++i) {
		cards.push_front(i);
	}

	while (cards.size() > 1) {
		cards.pop_back();
		cards.push_front(cards.back());
		cards.pop_back();
	}
	std::cout << cards.back() << std::endl;
}