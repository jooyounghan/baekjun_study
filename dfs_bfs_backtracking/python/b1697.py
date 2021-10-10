def get_mode(num, mode):
    if mode == 0:
        return num * 2
    if mode == 1:
        return num + 1
    if mode == 2:
        return num - 1

def bfs(begin, finish):
    visited[begin] = 1
    front = -1
    rear = 0
    queue = [0] * 200002
    queue[rear] = begin
    while front < rear:
        front += 1
        temp_start = queue[front]
        if temp_start == finish:
            print(visited[temp_start] - 1)
            return
        for mode in range(3):
            new_start = get_mode(temp_start, mode)
            if 0 <= new_start < 200002:
                if visited[new_start] == 0:
                    visited[new_start] = visited[temp_start] + 1
                    rear += 1
                    queue[rear] = new_start

start, end = map(int, input().split())
visited = [0] * 200002
bfs(start, end)