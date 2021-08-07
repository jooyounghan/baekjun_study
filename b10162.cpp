#include <iostream>

int main()
{
	int timer[3]{ 300, 60, 10 };
	int time;
	std::cin >> time;
	
	int main_idx = time / 300;
	bool flag = true;
	while (main_idx > -1 && flag)
	{
		int sub_idx = time - main_idx * 300;
		sub_idx = sub_idx / 60;
		for (int j = sub_idx; j > -1; j--)
		{
			int rest = time - main_idx * 300 - j * 60;
			if (rest % 10 == 0)
			{
				std::cout << main_idx << " " << j << " " << rest / 10 << " " << std::endl;
				flag = false;
				break;
			}
		}
		main_idx -= 1;
	}

	if (flag) {
		std::cout << -1 << std::endl;
	}
}