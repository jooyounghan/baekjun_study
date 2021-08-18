#include <iostream>
#include <string>
#include <vector>


int main() {
	std::string T;
	std::getline(std::cin, T);
	for (int i = 1; i < std::stoi(T) + 1; ++i) {
		std::vector<std::string> text_stack;
		std::string temp_texts;
		std::getline(std::cin, temp_texts);
		int start_idx = 0;
		int L = temp_texts.size();
		for (int idx = 0; idx < L; ++idx) {
			if (idx == L - 1) {
				text_stack.push_back(std::string(temp_texts.begin() + start_idx, temp_texts.begin() + idx + 1));
				break;
			}
			if (temp_texts[idx] == ' ') {
				text_stack.push_back(std::string(temp_texts.begin() + start_idx, temp_texts.begin() + idx));
				start_idx = idx + 1;
			}
		}

		std::cout << "Case #" << i << ": ";
		while (text_stack.size()) {
			std::cout << text_stack[text_stack.size() - 1] << " ";
			text_stack.pop_back();
		}
		std::cout << "\n";
	}
}
 