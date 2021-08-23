#include <iostream>
#include <string>

int main()
{
	std::string sentences;
	const char ucpc[4]{ 'U', 'C', 'P', 'C' }
	std::getline(std::cin, sentences);
	short start_idx = 0;
	bool flag = false;
	for (auto& sentence : sentences)
	{
		if (sentence == ucpc[start_idx]) {
			start_idx++;
		}
		if (start_idx == 4) {
			flag = true;
			break;
		}
	}

	if (flag) {
		std::cout << "I love UCPC" << std::endl;
	}
	else {
		std::cout << "I hate UCPC" << std::endl;
	}
	return 0;
}

