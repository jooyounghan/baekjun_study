#include <iostream>
#include <stack>
#include <string>

int main() {
	std::string parenth;
	std::cin >> parenth;
	
	std::stack<int> parstack;

	// 모든 값이 양수이므로, 열리는 괄호는 음수로 설정하여 차별성을 둔다.
	bool error_flag = false;
	for (int i = 0; i < parenth.size(); ++i) {
		if (parenth[i] == '(') {
			parstack.push(-1);
		}
		else if (parenth[i] == '[') {
			parstack.push(-2);
		}
		else if (!parstack.size()) {
			error_flag = true;
			break;
		}
		else {
			if (parstack.top() == -1 && parenth[i] == ')') {
				parstack.pop();
				parstack.push(2);
			}
			else if (parstack.top() == -2 && parenth[i] == ']') {
				parstack.pop();
				parstack.push(3);
			}
			else {
				int temp_num = 0;
				while (parstack.size() && parstack.top() != -1 && parstack.top() != -2) {
					temp_num += parstack.top();
					parstack.pop();
				}
				if (parstack.size() && parstack.top() == -1 && parenth[i] == ')') {
					parstack.pop();
					parstack.push(temp_num * 2);
				}
				else if (parstack.size() && parstack.top() == -2 && parenth[i] == ']') {
					parstack.pop();
					parstack.push(temp_num * 3);
				}
				else {
					error_flag = true;
					break;
				}
			}
		}
	}
	int result = 0;
	while (parstack.size() > 0) {
		if (parstack.top() == -1 || parstack.top() == -2) {
			error_flag = true;
			break;
		}
		result += parstack.top();
		parstack.pop();

	}

	if (error_flag) {
		std::cout << 0 << std::endl;
	}
	else {
		std::cout << result << std::endl;
	}
}