#include <iostream>
#include <queue>

int N;
int ballons[1000]{ 0 };
int infos[1000]{ 0 };

int rotate(int from, int step) {
	bool flag = true;
	if (step < 0) flag = false;
	step = step > 0 ? step : -step;
	for (int i = 0; i < step; ++i) {
		if (flag) {
			do
			{
				from += 1;
				from = from % N;
			} while (ballons[from] != 0);
		}

		else {
			do
			{
				from -= 1;
				if (from < 0) {
					from += N;
				}
			} while (ballons[from] != 0);
		}
	}
	return from;
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> infos[i];
	}

	std::queue<int> fires;
	fires.push(0);
	ballons[0] = 1;

	int cnt = 0;

	while (true) {
		int turn = fires.front();
		fires.pop();
		
		std::cout << turn + 1 << " ";
		cnt += 1;
		if (cnt == N) {
			break;
		}
		turn = rotate(turn, infos[turn]);	
		fires.push(turn);
		ballons[turn] = 1;
	}
}