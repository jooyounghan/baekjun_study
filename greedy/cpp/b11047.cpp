#include <iostream>

int main()
{
	int coins_value[10];
	unsigned int num_coins, values;
	std::cin >> num_coins >> values;
	
	for (int i = 0; i < num_coins; ++i) {
		std::cin >> coins_value[i];
	}

	int result = 0;
	for (int i = num_coins - 1; i > -1; --i) {
		result += values / coins_value[i];
		values = values % coins_value[i];
		if (!values) {
			break;
		}
	}

	std::cout << result << std::endl;
}