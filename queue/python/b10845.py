import sys

T = int(sys.stdin.readline())

a = []
for _ in range(T):
    command = sys.stdin.readline().split()
    length = len(a)
    if command[0] == "push":
        a.append(int(command[1]))
    elif command[0] == "front":
        if length == 0:
            print(-1)
        else:
            print(a[0])
    elif command[0] == "back":
        if length == 0:
            print(-1)
        else:
            print(a[-1])
    elif command[0] == "size":
        print(length)
    elif command[0] == "empty":
        if length == 0:
            print(1)
        else:
            print(0)
    elif command[0] == "pop":
        if length == 0:
            print(-1)
        else:
            print(a[0])
            a.pop(0)
    else:
        pass