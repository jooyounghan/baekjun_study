import sys

N = int(sys.stdin.readline())
heights = []
for i in range(N):
    temp = int(sys.stdin.readline())
    if i:
        while heights[-1] <= temp:
            heights.pop(-1)
            if not len(heights):
                break
        heights.append(temp)
    else:
        heights.append(temp)
print(len(heights))