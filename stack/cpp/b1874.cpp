#include <iostream>
#include <stack>
#include <string>

int n;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;

	std::stack<int> result;
	std::string result_text = "";
	int cmp_max = 1;
	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
	
		if (result.size()) {
			if (temp == result.top()) {
				result.pop();
				result_text += "-\n";
			}
			else if (temp < result.top()) {
				std::cout << "NO" << std::endl;
				return 0;
			}
			else {
				for (int j = cmp_max; j < temp + 1; ++j) {
					result.push(j);
					result_text += "+\n";
				}
				result.pop();
				result_text += "-\n";
				cmp_max = temp + 1;
			}

		}
		else {
			for (int j = cmp_max; j < temp + 1; ++j) {
				result.push(j);
				result_text += "+\n";
			}
			result.pop();
			result_text += "-\n";
			cmp_max = temp + 1;
		}
	}
	std::cout << result_text;
}
