#include <iostream>

int main() {
	int i, e;
	std::cin >> i >> e;
	int cnt = 1;
	while (i < e) {
		if (e % 2) {
			if (e % 10 != 1) {
				cnt = -1;
				break;
			}
			e = e / 10;
		}
		else{
			e = e / 2;
		}
		cnt++;
	}
	if (i != e) {
		cnt = -1;
	}
	std::cout << cnt << std::endl;
}