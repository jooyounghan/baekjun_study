L, R = map(int, input().split())

cnt_left = cnt_right = 0
while L != 1 and R != 1:
    if L < R:
        cnt_right += R // L
        R = R % L

    else:
        cnt_left += L // R
        L = L % R

if L != 1:
    cnt_left += L - 1
else:
    cnt_right += R - 1

print(cnt_left, cnt_right)