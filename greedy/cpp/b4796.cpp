#include <iostream>

int main() {
	int tc = 1;
	while (true) {
		int L, P, V;
		std::cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		int division, remainder;
		division = V / P;
		remainder = V % P;
		remainder = L < remainder ? L : remainder;
		int result = division * L + remainder;
		std::cout << "Case " << tc << ": " << result << "\n";
		tc += 1;
	}
}