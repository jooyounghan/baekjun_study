#include <iostream>
#include <vector>
#include <string>

int sudoku[9][9];
std::vector<std::pair<int, int>> check_queue;

bool check_row_col(const int& row, const int& col, const int& cmp) {
    for (int k = 0; k < 9; ++k) {
        if (sudoku[row][k] == cmp || sudoku[k][col] == cmp) {
            return false;
        }
    }
    return true;
}

bool check_small_box(const int& row, const int& col, const int& cmp) {
    for (int r = 3 * (row / 3); r < 3 * (row / 3) + 3; ++r) {
        for (int c = 3 * (col / 3); c < 3 * (col / 3) + 3; ++c) {
            if (sudoku[r][c] == cmp) {
                return false;
            }
        }
    }
    return true;
}

void backtracking(const int& front, const int& rear) {
    if (front == rear) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                std::cout << sudoku[r][c];
            }
            std::cout << '\n';
        }
        exit(0);
    }

    int& new_row = check_queue[front + 1].first;
    int& new_col = check_queue[front + 1].second;
    for (int i = 1; i < 10; ++i) {
        if (check_small_box(new_row, new_col, i) && check_row_col(new_row, new_col, i)) {
            sudoku[new_row][new_col] = i;
            backtracking(front + 1, rear);
            sudoku[new_row][new_col] = 0;
        }
    }
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R, C;
    R = 9;
    C = 9;

    for (int r = 0; r < 9; ++r) {
        std::string temp;
        std::cin >> temp;
        for (int c = 0; c < 9; ++c) {
            sudoku[r][c] = temp[c] - '0';
        }
    }

    check_queue.reserve(81);
    
    int front = -1;
    int rear = -1;

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (sudoku[r][c] == 0) {
                rear += 1;
                check_queue.push_back(std::make_pair(r, c));
            }
        }
    }
    backtracking(front, rear);
}
