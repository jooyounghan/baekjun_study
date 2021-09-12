k = int(input())
kk = 2 ** k

buildings = [0] * kk
drawings = list(map(int, input().split()))
drawing_idx = 0

def draw(i):
    global drawing_idx
    if (i * 2 >= kk or buildings[i * 2]):
        buildings[i] = drawings[drawing_idx]
        drawing_idx += 1
        return
    draw(i * 2)
    draw(i)
    draw(i * 2 + 1)
    return

draw(1)
for i in range(1, k + 1):
    for j in range(2 ** (i-1), 2 ** i):
        print(buildings[j], end=" ")
    print()