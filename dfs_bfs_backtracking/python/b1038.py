def bfs():
    queue = [0] * 1000000
    for i in range(10):
        queue[i] = str(i)
    
    front = -1
    rear = 9
    while front != rear:
        front += 1
        temp_string = queue[front]
        if front == N:
            print(temp_string)
            return
        for i in range(int(temp_string[-1])):
            rear += 1
            queue[rear] = temp_string + str(i)
    print(-1)

N = int(input())
bfs()