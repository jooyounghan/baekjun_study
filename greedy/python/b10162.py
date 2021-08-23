times = int(input())
flag = True
idx = times//300
while(idx > -1 and flag) :
    for j in range((times - 300 * idx) // 60, -1, -1) :
        if ((times - 300 * idx - 60 * j) % 10 == 0) :
            print("{} {} {}".format(idx, j, (times - 300 * idx - 60 * j) // 10))
            flag = False
            break
    idx -= 1

if flag :
    print(-1)