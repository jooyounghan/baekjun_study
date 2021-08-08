#include<iostream>
#include<string>

int main()
{
	std::string expression;
	std::cin >> expression;

	int result = 0;
	int idx = 0;
	int nums = 0;
	bool flag = false;
	for (int i = 0; i < expression.size() + 1; ++i) {
		if (expression[i] == '-' || expression[i] == '+' || expression[i] == '\0') {
			if (flag) {
				result -= stoi(expression.substr(idx, nums));
			}
			else {
				result += stoi(expression.substr(idx, nums));
			}
			idx = i + 1;
			nums = 0;
			if (expression[i] == '-') { flag = true; }
			continue;
		}
		nums += 1;

	}
	std::cout << result << std::endl;
}