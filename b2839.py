sugar = int(input())
main_idx = sugar // 5
flag = True
for idx in range(main_idx, -1, -1) :
	rest = sugar - 5 * idx
	if rest % 3 == 0 :
		print(idx + (rest // 3))
		flag = False
		break
if flag :
	print(-1)