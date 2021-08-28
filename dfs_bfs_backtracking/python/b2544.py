def BFS(relation_list, start, end):
    visited = [0] * (N + 1)
    visited[start] = 1

    check_queue = [start] * (N + 1)
    front = 0
    rear = 1

    while front < rear:
        check_node = check_queue[front]
        front += 1

        if check_node == end:
            return visited[check_node] - 1

        for relation in relation_list[check_node]:
            if not visited[relation]:
                visited[relation] = visited[check_node] + 1
                check_queue[rear] = relation
                rear += 1
    return -1

N = int(input())
start, end = map(int, input().split())
num_relations = int(input())

relation_list = [[] for _ in range(N + 1)]
for _ in range(num_relations):
    temp_start, temp_end = map(int, input().split())
    relation_list[temp_start].append(temp_end)
    relation_list[temp_end].append(temp_start)
print(BFS(relation_list, start, end))
