import sys

book_num = int(input())
book_list = dict()

for i in range(0,book_num):
    book_list[int(sys.stdin.readline())] = i

result = 0
idx = -1
for i in range(book_num-1, 0, -1) :
    if(book_list[i] > book_list[i + 1]) :
        book_list[i] = idx
        idx -= 1
        result += 1

print(result)