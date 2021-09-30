#include<iostream>

int main() {
	unsigned long long L, R;
	unsigned long long cnt_left = 0;
	unsigned long long cnt_right = 0;

	std::cin >> L >> R;
	while (L != 1 && R != 1) {
		if (L < R) {
			cnt_right += R / L;
			R = R % L;
		}
		else {
			cnt_left += L / R;
			L = L % R;
		}
	}
	if (L != 1) {
		cnt_left += L - 1;
	}
	if (R != 1) {
		cnt_right += R - 1;
	}

	std::cout << cnt_left << " " << cnt_right << std::endl;
}