#include <iostream>
#include <queue>

int N;
std::queue<int> router;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;

	while (true) {
		int packet;
		std::cin >> packet;

		if (packet == -1) {
			break;
		}
		if (packet == 0) {
			router.pop();
			continue;
		}

		if (router.size() < N) {
			router.push(packet);
		}
	}

	if (router.size()) {
		for (int i = 0; i < router.size(); ++i){
			std::cout << router.front() << " ";
			router.pop();
			i -= 1;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "empty" << std::endl;
	}
}