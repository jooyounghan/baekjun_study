#include <vector>
#include <iostream>
int main() {
	std::vector<int> note;
	note.reserve(100000);
	
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int temp;
		std::cin >> temp;
		if (temp) {
			note.push_back(temp);
			continue;
		}
		note.pop_back();
	}

	int total = 0;
	for (int i = 0; i < note.size(); ++i) {
		total += note[i];
	}
	std::cout << total << std::endl;
}