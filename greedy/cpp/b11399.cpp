#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	short test_case;
	std::cin >> test_case;
	std::vector<short> times;
	times.resize(test_case);
	for (short i = 0; i < test_case; i++)
	{
		std::cin >> times[i];
	}
	std::sort(times.begin(), times.end());

	int total = 0;

	for (short i = 0; i < times.size(); i++)
	{
		for (short j = 0; j < i + 1; j++)
		{
			total += times[j];
		}
	}
	std::cout << total << std::endl;
}