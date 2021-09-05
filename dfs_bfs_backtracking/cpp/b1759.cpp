#include <iostream>
#include <string>
#include <algorithm>

void backtracking(char(&word_lists)[15], int pos, std::string text, int vowels, int cons, const int& L, const int& C) {
	if (text.size() == L) {
		if (vowels > 0 && cons > 1) {
			std::cout << text << std::endl;
		}
		return;
	}

	else {
		for (int i = pos; i < C; ++i) {
			const char& word = word_lists[i];
			if (word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u') {
				backtracking(word_lists, i + 1, text + word, vowels + 1, cons, L, C);
			}
			else {
				backtracking(word_lists, i + 1, text + word, vowels, cons + 1, L, C);
			}
		}
	}
	return;
}

int main()
{
	int L, C;
	std::cin >> L >> C;
	char word_list[15];
	for (int i = 0; i < C; ++i) {
		std::cin >> word_list[i];
	}
	std::sort(word_list, word_list + C);

	backtracking(word_list, 0, "", 0, 0, L, C);

}