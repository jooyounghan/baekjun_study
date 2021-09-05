#include <iostream>
#include <vector>
int players[20][20];
int N;
int min_gap = 10000;


int get_status(std::vector<int> team) {
	int team_status = 0;
	for (int i = 0; i < team.size(); ++i) {
		for (int j = 0; j < team.size(); ++j) {
			team_status += players[team[i]][team[j]];
		}
	}
	return team_status;
}


void backtracking(std::vector<bool>& team_status, const int& pos, const int& cnt) {
	if (cnt == N / 2) {
		std::vector<int> team1;
		std::vector<int> team2;
		for (int i = 0; i < team_status.size(); ++i) {
			if (team_status[i]) { team1.push_back(i); }
			else { team2.push_back(i); }
		}
		int team1_status = get_status(team1);
		int team2_status = get_status(team2);

		int temp_gap = team1_status > team2_status ? (team1_status - team2_status) : (team2_status - team1_status);
		if (temp_gap < min_gap) {
			min_gap = temp_gap;
		}
		return;
	}

	if ((N/2) < pos - cnt) {
		return;
	}

	team_status[pos] = 1;
	backtracking(team_status, pos + 1, cnt + 1);
	team_status[pos] = 0;
	backtracking(team_status, pos + 1, cnt);
	return;
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> players[i][j];
		}
	}

	std::vector<bool> team_status;
	team_status.resize(N);
	backtracking(team_status, 0, 0);
	
	std::cout << min_gap << std::endl;
}