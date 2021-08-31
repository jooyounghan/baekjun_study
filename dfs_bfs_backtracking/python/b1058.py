def bfs(connections, N):
    max_num = 0
    for person in range(N):
        temp_num = 0
        visited = [0] * N
        check_queue = [0] * N
        front = 0
        rear = 1 
        check_queue[0] = person
        visited[person] = 1
        while front < rear:
            check = check_queue[front]
            front += 1
            if visited[check] > 1:
                temp_num += 1
                if visited[check] == 3:
                    continue
            for connection in connections[check]:
                if not visited[connection]:
                    check_queue[rear] = connection
                    rear += 1
                    visited[connection] = visited[check] + 1
        if temp_num > max_num:
            max_num = temp_num
    return max_num

N = int(input())
connections = [[] for _ in range(N)]

for i in range(N):
    temp_list = input()
    for idx in range(N):
        if temp_list[idx] == 'Y':
            connections[i].append(idx)
print(bfs(connections, N))
