#include <iostream>

int main()
{
	unsigned short check_set[2]{ 5, 3 };
	unsigned short sugar;
	std::cin >> sugar;

	unsigned short main_idx = sugar / check_set[0];
	for (short idx = main_idx; idx > -1; idx--) {
		unsigned plastic_bag = idx;
		unsigned short rest = sugar - 5 * idx;
		if (rest % check_set[1] == 0) {
			plastic_bag += rest / check_set[1];
			std::cout << plastic_bag;
			return 0;
		}
	}
	std::cout << -1 << std::endl;
	return 0;
}