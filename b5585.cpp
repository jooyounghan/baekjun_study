#include <iostream>
#include <string>
#include <iostream>
int main()
{
	short changes[6] = { 500, 100, 50, 10, 5, 1 };
	short money;
	std::cin >> money;
	money = 1000 - money;
	short cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		short temp = money / changes[i];
		cnt += temp;
		money -= temp * changes[i];
	}
	std::cout << cnt << std::endl;
	return 0;
}