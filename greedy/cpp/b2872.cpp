#include <iostream>
#include <map>

int main()
{
	int result = 0;
	int num_books;
	std::cin >> num_books;
	int book_table[300001];

	for (int i = 1; i < num_books + 1; ++i) {
		int book;
		std::cin >> book;
		book_table[book] = i;
	}

	int idx = -1;
	for (int i = num_books - 1; i > 0; --i) // 1 ~ num_books - 1까지를 확인한다.
	{
		if (book_table[i] > book_table[i + 1]) {
			book_table[i] = idx;
			idx -= 1;
			result += 1;
		}
	}
	std::cout << result << std::endl;
}
