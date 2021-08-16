i, e = map(int, input().split())
cnt = 1
while i < e:
    if e % 2:
        if e % 10 != 1:
            break
        e = e // 10
    else:
        e = e // 2
    cnt += 1
if i != e:
    cnt = -1
print(cnt)