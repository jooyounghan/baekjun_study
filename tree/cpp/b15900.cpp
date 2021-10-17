#include <iostream>
#include <vector>
#include <queue>

int N;
unsigned long long cnt = 0;
int visited[500001]{ 0 };

std::vector<std::vector<int>> adj;

void bfs(const int& start) {
    visited[start] = 1;
    std::queue<int> check;
    check.push(start);

    bool flag = true;
    while (check.size()) {
        int check_node = check.front();
        check.pop();
        flag = true;
        for (auto& adj_node : adj[check_node]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = visited[check_node] + 1;
                check.push(adj_node);
                flag = false;
            }
        }
        if (flag) {
            cnt += visited[check_node] - 1;
        }
    }

}

int main() {
    std::cin >> N;
    adj.resize(N + 1);
    int node1, node2;
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    bfs(1);
    if (cnt % 2) std::cout << "Yes" << '\n';
    else std::cout << "No" << '\n';
}