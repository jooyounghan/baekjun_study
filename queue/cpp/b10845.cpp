#include <iostream>
#include <string>

class queue {
public:
	int back_idx;
	int front_idx;
	int* data;

public:
	queue() : back_idx(0), front_idx(0), data(nullptr) {}

	void push(const int& item) {
		if (back_idx == 0) {
			if (data != nullptr) {
				delete[] data;
			}
			back_idx += 1;
			data = new int[back_idx];
			data[back_idx - 1] = item;
			return;
		}
		back_idx += 1;
		int* temp = new int[back_idx];
		for (int i = 0; i < back_idx - 1; ++i) {
			temp[i] = data[i];
		}
		temp[back_idx - 1] = item;
		delete[] data;
		data = temp;
	}

	int pop() {
		if (back_idx == 0) {
			std::cout << -1 << std::endl;
			return -1;
		}
		back_idx -= 1;
		int* temp = new int[back_idx];
		for (int i = 0; i < back_idx; ++i) {
			temp[i] = data[i + 1];
		}
		int pop_data = data[0];
		std::cout << pop_data << std::endl;
		delete[] data;
		data = temp;
		return pop_data;
	}

	int size() {
		std::cout << back_idx - front_idx << std::endl;
		return back_idx - front_idx;
	}

	int empty() {
		if (back_idx - front_idx) {
			std::cout << 0 << std::endl;
			return 0;
		}
		std::cout << 1 << std::endl;
		return 1;
	}

	int front() {
		if (back_idx - front_idx) {
			std::cout << data[front_idx] << std::endl;
			return data[front_idx];
		}
		std::cout << -1 << std::endl;
		return -1;
	}

	int back() {
		if (back_idx - front_idx) {
			std::cout << data[back_idx - 1] << std::endl;
			return data[back_idx - 1];
		}
		std::cout << -1 << std::endl;
		return -1;
	}
};



int main() {
	int lines;
	std::cin >> lines;
	queue a;
	for (int line = 0; line < lines; ++line) {
		std::string command;
		std::cin >> command;
		if (command == "push") {
			int item;
			std::cin >> item;
			a.push(item);
		}
		else if (command == "front") {
			a.front();
		}
		else if (command == "back") {
			a.back();
		}
		else if (command == "size") {
			a.size();
		}
		else if (command == "empty") {
			a.empty();
		}
		else if (command == "pop") {
			a.pop();
		}
	}
}