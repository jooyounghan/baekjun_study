#include <iostream>
#include <math.h>
int k;
int kk;
int buildings[1024];

void draw_to_buildings(const int& i) {
	if (i * 2 >= kk || buildings[i * 2]) {
		std::cin >> buildings[i];
		return;
	}
	draw_to_buildings(i * 2);
	draw_to_buildings(i);
	draw_to_buildings(i * 2 + 1);
}

int main() {
	std::cin >> k;
	kk = std::pow(2, k);
	draw_to_buildings(1);
	for (int i = 1; i <= k; ++i) {
		for (int j = std::pow(2, i - 1); j < std::pow(2, i); ++j) {
			std::cout << buildings[j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}