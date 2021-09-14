T = int(input())

def get_parent(start, node_list):
    while start:
        node_list.append(start)
        start = nodes[start]    

def get_same_parent(node1_list, node2_list):
    idx = 0
    while True:
        if idx > len(node1_list) - 1 or idx > len(node2_list) - 1:
            idx -= 1
            break

        if node1_list[len(node1_list) - 1 - idx] == node2_list[len(node2_list) - 1 - idx]:
            idx += 1
            continue
        else :
            idx -= 1
            break
    return node1_list[len(node1_list) - 1 - idx]

for tc in range(T):
    N = int(input())

    nodes = [0] * (N + 1)

    for i in range(1, N):
        parent, child = map(int, input().split())
        nodes[child] = parent
    node1, node2 = map(int, input().split())
    node1_list = []
    node2_list = []
    get_parent(node1, node1_list)
    get_parent(node2, node2_list)

    print(get_same_parent(node1_list, node2_list))